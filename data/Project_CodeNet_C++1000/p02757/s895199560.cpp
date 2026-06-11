#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T&a , T b){ if(a<b){ a=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&a , T b){ if(a>b){ a=b; return true; } else{ return false; } } 

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    ll n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll ans=0;
    reverse(s.begin(),s.end());
    if(p==2){
        for(ll i=0;i<n;i++){
            if((s[i]-'0')%2==0){
                ans += n-i;
            }
        }
    }else if(p==5){
        for(ll i=0;i<n;i++){
            if((s[i]-'0')%5==0){
                ans += n-i;
            }
        }
    }else{
        ll k = 1;
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            a[i] = (s[i]-'0')*k%p;
            k = k*10%p;
        }
        vector<ll> cum(n+1);
        cum[0] = 0;
        for(ll i=0;i<n;i++){
            cum[i+1] = (cum[i] + a[i])%p;
        }
        vector<ll> t(p);
        for(ll i=0;i<=n;i++){
            t[cum[i]]++;
        }
        for(ll i=0;i<p;i++){
            ans += (ll)t[i]*(t[i]-1)/2;
        }
    }
    cout << ans << endl;
}