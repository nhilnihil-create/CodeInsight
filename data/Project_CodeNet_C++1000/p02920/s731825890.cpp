#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1234567890


int main(){
    ll i,j;
    ll n;
    cin>>n;
    ll m=1;
    for(i=0;i<n;i++) m*=2;
    multiset<ll> s;
    ll M;
    for(i=0;i<m;i++) {
        ll x;
        cin>>x;
        s.insert(-x);
        M=max(M,x);
    }

    vector<ll> v;

    ll tem=0;
    for(i=0;i<=n;i++){
        if(i==0) {
            v.pb(-M);
            s.erase(s.find(-M));
        }
        else {
            ll tem2=tem;
            for(j=0;j<(1<<(i-1));j++){
                if(s.upper_bound(v[j])==s.end()){
                    cout<<"No"<<endl;
                    return 0;
                }
                else {
                    v.pb(*s.upper_bound(v[j]));
                    s.erase(s.upper_bound(v[j]));
                }
            }
            
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}