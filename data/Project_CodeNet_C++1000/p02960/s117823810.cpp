#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fill(x,v) memset(x,v,sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x <<": " << x << endl

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef long double C;

const int MAX = 1e5+5;
const ll MOD = 1e9+7;

ll dp[13][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    fill(dp, 0);
    dp[0][0] = 1;
    ll rest;
    rep(i,0,s.size()){
        rep(j,0,13){
            rest = (j*10)%13;
            if(s[i] == '?'){
                rep(k,0,10){
                    ll ind = (rest+k)%13; 
                    //trace(ind);
                    dp[ind][i+1] = (dp[ind][i+1] + dp[j][i])%MOD;
                }
            }
            else{
                ll dig = s[i] - '0';
                ll ind = (rest+dig)%13; 
                dp[ind][i+1] = (dp[ind][i+1] + dp[j][i])%MOD;
            }
        }
    }
    cout << dp[5][s.size()] << endl;
    return 0;
}