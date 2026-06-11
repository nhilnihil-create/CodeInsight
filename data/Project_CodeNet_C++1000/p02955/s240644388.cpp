#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll n,k,r,w,q,qq,p;
multiset<ll> z,zz;
bool b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ll x[n];
    for(ll i=0;i<n;i++) cin>>x[i],r+=x[i];

    for(ll i=1;i*i<=r;i++){
        if(r%i!=0) continue;
        w=r/i;
        z.clear();
        zz.clear();
        q=0;
        qq=0;
        p=0;
        b=true;
        for(ll j=0;j<n;j++){
            if(x[j]%w<(w-x[j]%w) || (x[j]%w==(w-x[j]%w) && b)){
                z.insert(x[j]%w);
                q+=x[j]%w;
                if(x[j]%w==(w-x[j]%w)) b=false;
            }
            else{
                zz.insert(w-x[j]%w);
                qq+=w-x[j]%w;
                if(x[j]%w==(w-x[j]%w)) b=true;
            }
        }
        while(q!=qq){
                if(q>qq){
                    if(z.size()==0) break;
                    auto t=z.rbegin();
                    q-=*t;
                    qq+=(w-*t);
                    z.erase(z.find(*t));
                }
                else{
                    if(zz.size()==0) break;
                    auto t=zz.rbegin();
                    qq-=*t;
                    q+=(w-*t);
                    zz.erase(zz.find(*t));
                }
        }

        if(q==qq && q<=k){
            cout<<w;
            return 0;
        }
    }


    for(ll i=sqrt(r);i>=1;i--){
        if(r%i!=0) continue;
        w=i;
        z.clear();
        zz.clear();
        q=0;
        qq=0;
        p=0;
        b=true;
        for(ll j=0;j<n;j++){
            if(x[j]%w<(w-x[j]%w) || (x[j]%w==(w-x[j]%w) && b)){
                z.insert(x[j]%w);
                q+=x[j]%w;
                if(x[j]%w==(w-x[j]%w)) b=false;
            }
            else{
                zz.insert(w-x[j]%w);
                qq+=w-x[j]%w;
                if(x[j]%w==(w-x[j]%w)) b=true;
            }
        }
        while(q!=qq){
                if(q>qq){
                    if(z.size()==0) break;
                    auto t=z.rbegin();
                    q-=*t;
                    qq+=(w-*t);
                    z.erase(z.find(*t));
                    p+=*t;
                }
                else{
                    if(zz.size()==0) break;
                    auto t=zz.rbegin();
                    qq-=*t;
                    q+=(w-*t);
                    zz.erase(zz.find(*t));
                    p+=*t;
            }
        }

        if(q==qq && q<=k){
            cout<<w;
            return 0;
        }
    }
    cout<<n;


}
