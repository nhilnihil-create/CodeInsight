#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int N;
int A[300010];
ll acc[300010];
ll acc2[300010];
ll ans[300010];

int main ()
{
    cin >> N;
    REP(i,N) cin >> A[i];
    map < int,int > cnt;
    REP(i,N) cnt[A[i]]++;

    for (auto &a : cnt) {
        acc[a.second]++;
        acc2[a.second]++;
    }
    
    REP(i,300005) {
        acc[i] *= (ll)i;
    }
    
    REP(i,300005) {
        acc[i + 1] = acc[i] + acc[i + 1];
        acc2[i + 1] = acc2[i] + acc2[i + 1];
    }

    for (ll i = 1; i <= N; i++) {
        ans[i] = acc[i] + (acc2[N] - acc2[i]) * i;
        ans[i] /= i;
    }

    for (ll K = 1; K <= N; K++) {
        ll l = 0, r = N + 1;
        while (r - l > 1) {
            ll mid = (r + l) / 2;
            if (K <= ans[mid]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }

    return 0;
}
