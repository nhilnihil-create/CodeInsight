#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    cin>>n;
    vector<ll> a,b,c;
    ll tmp;
    rep(i,n){
        cin>>tmp;
        a.push_back(tmp);
    }
    rep(i,n){
        cin>>tmp;
        b.push_back(tmp);
    }
    rep(i,n-1){
        cin>>tmp;
        c.push_back(tmp);        
    }
    ll sum=0;
    ll old_soeji=a[0];
    ll soeji;
    rep(i,n){
        soeji = a[i];
        sum+=b[soeji-1];
        if(soeji-old_soeji==1){
            sum+=c[old_soeji-1];
        }
        old_soeji = soeji;
    }
    cout<<sum<<endl;

}
