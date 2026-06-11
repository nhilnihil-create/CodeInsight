#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> divisor(ll n){
    vector<ll> v;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){v.push_back(i);v.push_back(n/i);}
    }
    sort(v.rbegin(),v.rend());
    return v;
}


int main(){
    int n;cin>>n;
    ll k;cin>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll sum=accumulate(v.begin(),v.end(),0ll);
    vector<ll> di=divisor(sum);
    for(int i=0;i<di.size();i++){
        ll cur=0;
        vector<ll> res;
        for(int j=0;j<n;j++){
            cur+=v[j]%di[i];
           if(v[j]%di[i]) res.push_back(v[j]%di[i]);
        }
        if(cur%di[i]==0){
            int yay=cur/di[i];
            sort(res.rbegin(),res.rend());
            ll ss=0;
            for(int kk=0;kk<yay;kk++)ss+=di[i]-res[kk];
           if(ss<=k){ cout<<di[i]<<endl;return 0;}}
    }
}