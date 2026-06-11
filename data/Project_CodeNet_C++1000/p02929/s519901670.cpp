#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
#define int long long
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
const ll MOD = 1e9+7;
signed main(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[0]=='W'){
        cout << 0 << endl;
        return 0;
    }
    vector<bool> r(2*n,0);
    rep(i,2*n){
        if(i==0){
            r[0]=0;
        }
        else if(s[i-1]==s[i]){
            if(r[i-1]) r[i]=0;
            else r[i]=1;
        }else{
            r[i]=r[i-1];
        }
    }
    int cnt=0;
    rep(i,2*n) if(r[i]) cnt++;
    if(cnt!=n){
        cout << 0 << endl;
        return 0;
    }
    int res=0;
    ll ans=1;
    rrep(i,2*n){
        if(r[i]) res++;
        else{
            ans*=res;
            res--;
        }
        ans%=MOD;
    }
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    cout << ans << endl;
}
