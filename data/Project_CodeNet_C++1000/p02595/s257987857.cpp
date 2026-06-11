#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

ll mod = 1e9 + 7;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, d; cin >> n >> d;
    ll x[n], y[n];
    rep(i, n){
        cin >> x[i] >> y[i];
    }

    ll d2 = d * d;
    ll cnt = 0;
    rep(i, n){
        if(x[i] * x[i] + y[i] * y[i] <= d2){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}