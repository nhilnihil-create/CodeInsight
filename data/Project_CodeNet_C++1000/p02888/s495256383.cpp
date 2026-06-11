#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int L[2010];
    rep(i, N) cin >> L[i];
    sort(L, L + N);
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int ok1 = j;
            int ng1 = N;
            int ok2 = N;
            int ng2 = j - 1;
            while(abs(ok1 - ng1) > 1) {
                int mid = (ok1 + ng1) / 2;
                if(abs(L[j] - L[mid]) < L[i]) ok1 = mid;
                else ng1 = mid;
            }
            while(abs(ok2 - ng2) > 1) {
                int mid = (ok2 + ng2) / 2;
                if(L[i] < L[j] + L[mid]) ok2 = mid;
                else ng2 = mid;
            }
            //cout << ok1 << " " << ok2 << endl;
            ans += ok1 - ok2;
        }
    }
    cout << ans << endl;

    return 0;
}
// abs(b - c) < a < b + c, 