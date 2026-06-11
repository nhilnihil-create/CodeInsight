#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll idx = lower_bound(A.begin(), A.end(), 0) - A.begin();
    vector<ll> x(N-1), y(N-1);
    ll tmp = 0;
    auto disp = [](vector<ll> a) {
        for (ll e : a) {
            cout << e << " ";
        }
        cout << "\n";
    };
    // disp(A);
    if (idx == 0) {
        idx = 1;
    } else if (idx == N) {
        idx = N-1;
    }
    Rep (i, N-idx-1) {
        x[tmp] = A[0];
        y[tmp] = A[idx+i];
        A[0] -= A[idx+i];
        A[idx+i] = 0;
        tmp++;
        // disp(A);
    }



    Rep (i, idx) {
        x[tmp] = A[N-1];
        y[tmp] = A[i];
        A[N-1] -= A[i];
        A[i] = 0;
        tmp++;
        // disp(A);
    }

    cout << A[N-1] << "\n";
    Rep (i, N-1) {
        cout << x[i] << " " << y[i] << "\n";
    }
}