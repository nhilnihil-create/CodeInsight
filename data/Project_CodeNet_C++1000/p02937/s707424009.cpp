#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }


vector<vector<ll>> x(30);
ll y[30],z[30],z2[30];
int main(){
    string s,t;
    bool f=true,q=true;
    cin>>s>>t;
    ll sl=s.length(),tl=t.length();
    rep(i,0,sl){
        ll zz=s[i]-'a';
        x[zz].pb(i);
        z[zz]++;
    }
    rep(i,0,tl)z2[t[i]-'a']++;
    rep(i,0,30)if(z[i]==0&&z2[i]>0)q=false;
    ll pos=0,num,roop=-1,last;
    while(q&&pos<tl&&roop<1e6){
        f=true;
        num=-1;
        roop++;
        rep(i,0,30)y[i]=0;
        while(f&&pos<tl){
            ll zzz=(ll)(t[pos]-'a');
            while(x[zzz][y[zzz]]<num&&z[zzz]>y[zzz])y[zzz]++;
            if(z[zzz]>y[zzz]&&x[zzz][y[zzz]]>=num){
                num=x[zzz][y[zzz]];
                y[zzz]++;
                pos++;
                if(pos==tl)last=num;
            }
            else f=false;
        }
    }
    if(!q||roop==1e6)cout<<-1<<endl;    
    else cout<<roop*sl+last+1<<endl;

}
