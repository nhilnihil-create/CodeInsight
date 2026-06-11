#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    ll n;
    cin>>n;
    vll a(n);
    rell(i,n) cin>>a[i];
    ll max=1000006;
    vll sub(max,max);
    rell(i,max){
        if(i==0) continue;
        else if(i==1) sub[i]=1;
        else if(sub[i]!=max) continue;
        else{
            sub[i]=i;
            for(ll j=1;i*j<=max; j++){
                if(sub[i]!=max) sub[i*j]=i;
            }
        }
    }
   
    set<ll> div;
    bool pa=true;
    rell(i,n){
        ll j=a[i];
        set<ll> divin;
        while(j!=1){
            
            divin.insert(sub[j]);
            j/=sub[j];
        }
        for(auto value:divin){
            if(div.count(value)) pa=false;
            else div.insert(value);
        }
        if(!pa){
            break;
        }
    }
    if(pa){
        cout<<"pairwise coprime"<<endl;
        return 0;
    }
    ll gc=a[0];
    rell(i,n){
        gc=gcd(gc,a[i]);
    }
    if(gc==1){
        cout<<"setwise coprime"<<endl;
        return 0;
    }
    cout<<"not coprime"<<endl;
  

}
