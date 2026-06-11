#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0, up = 0, down = 0;
    int state = 0;
    REP(i, n){
        if(state == 0){
            if(s[i] == '<'){
                up++;
            }else{
                down++;
                state = 1;
            }
        }else{
            if(s[i] == '<'){
                ll a = max(up, down), b = min(up, down);
                ans += a*(a+1)/2 + b*(b-1)/2;
                up = 1;
                down = 0;
                state = 0;
            }else{
                down++;
            }
        }
    }

    ll a = max(up, down), b = min(up, down);
    ans += a*(a+1)/2 + b*(b-1)/2;

    cout << ans << endl;
    return 0;
}
