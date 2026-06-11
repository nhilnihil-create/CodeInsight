#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,1000){
        int now = i;
        string t = "";
        rep(j,3){
            t += '0' + now%10;
            now /= 10;
        }
        int itr = 0;
        int itr_t = 0;
        while(itr < n){
            if(s[itr] == t[itr_t]){
                itr++;
                itr_t++;
                if(itr_t == 3){
                    ans++;
                    break;
                }
            }
            else itr++;
        }
    }
    cout << ans << endl;
    return 0;
}