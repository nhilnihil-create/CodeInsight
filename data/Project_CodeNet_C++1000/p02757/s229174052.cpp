#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// Still trying to be normal
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).saize()
using namespace std;
const ll INF = 1e17 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll ans=0;
    if(p!=2 && p!=5){
        ll mod[10000];
        memset(mod,0,sizeof mod);
        mod[0]=1;
        ll ant=0;
        ll base = 1;
        per(i,n,0){
            ll ant2=ant;
            ll modact = (ant+(((s[i]-'0')%p)*base)%p)%p;
            ant=modact;
            // cout<<modact<<" "<<mod[modact]<<endl;
            if(s[i]!='0')ans+=mod[modact];
            else ans+=mod[ant2];
            base*=10;
            base%=p;
            mod[modact]++;
        }
    }
    if(p==2){
        ll qtp=0;
        // if((s[s.size()-1]-'0')%2==0)qtp++;
        per(i,n,0){
            ans+=qtp+((s[i]-'0')%2==0);
            if((s[i]-'0')%2==0)qtp++;
        }
    }
    else if(p==5){
        ll qt50=0;
        // if(s[s.size()-1]=='0' || s[s.size()-1]=='5')qt50++;
        per(i,n,0){
            ans+=qt50+((s[i]-'0')==0 || (s[i]-'0')==5);
            if(((s[i]-'0')==0 || (s[i]-'0')==5))qt50++;
        }
    }
    cout<<ans<<'\n';
    return 0;   
}