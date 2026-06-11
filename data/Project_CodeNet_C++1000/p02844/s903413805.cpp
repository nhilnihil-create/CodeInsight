#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    rep(i, 1000){
        int hyaku = i/100;
        int ju = (i/10)%10;
        int iti = i%10;

        bool flag_100 = false;
        bool flag_10 = false;
        bool flag_1 = false;

        rep(j, n){
            if(!flag_100){
                if(s[j]-'0'==hyaku){
                    flag_100=true;
                    continue;
                }
            }
            if(flag_100 && !flag_10){
                if(s[j]-'0'==ju){
                    flag_10=true;
                    continue;
                }
            }
            if(flag_10 && !flag_1){
                if(s[j]-'0'==iti){
                    ans++;
                    //printf("%d, %d, %d\n", hyaku, ju, iti);
                    flag_1=true;
                    continue;
                }
            }
            if(flag_1) break;
        }
    }

    cout << ans << endl;

    return 0;
}