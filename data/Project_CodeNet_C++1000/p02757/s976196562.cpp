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
#define int long long

int cnt[10010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, P; cin >> N >> P;
    string S; cin >> S;
    if(P == 2 || P == 5) {
        int ans = 0;
        RREP(i, N - 1, 0) {
            int num = S[i] - '0';
            if(num % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    int sum = 0;
    int times = 1;
    rep(i, N) {
        sum += ((S[N - i - 1] - '0') * times) % P;
        sum %= P;
        cnt[sum]++;
        times = (times * 10) % P;
    }
    // rep(i, P) cout << cnt[i] << " ";
    // cout << endl;
    int ans = 0;
    int k = 0;
    times = 1;
    rep(i, N) {
        ans += cnt[k % P];
        int num = (S[N - i - 1] - '0') % P;
        k += num * times;
        k %= P;
        cnt[k % P]--;
        //cout << ans << " " <<k % P << " " << (-k + P * 10) % P<< endl;
        times = (times * 10) % P;
    }
    cout << ans << endl;


    return 0;
}
// 0 1 2 3 4 5 6
// 0