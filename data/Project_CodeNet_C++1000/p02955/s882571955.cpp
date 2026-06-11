#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> p;
ll a[505],n,k,sum,sum1[505],sum2[505];
bool check(ll x){
    vector<pair<ll,ll>> b;
    b.push_back({0,0});
    for(int i=1;i<=n;i++){
        if(a[i]%x==0) b.push_back({0,0});
        else b.push_back({a[i]%x,x-a[i]%x});
    }
    sort(b.begin(),b.end());
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+b[i].first;
        sum2[i]=sum2[i-1]+b[i].second;
    }
    for(int i=1;i<=n;i++){
        if(sum1[i]==sum2[n]-sum2[i]){
            return sum1[i]<=k;
        }
    }
    return false;
}
int main(){
    ll i;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(i=1;i*i<sum;i++){
        if(sum%i==0){
            p.push_back(i);
            p.push_back(sum/i);
        }
    }
    if(i*i==sum) p.push_back(i);
    sort(p.begin(),p.end());
    for(int i=p.size()-1;i>=0;i--){
        if(check(p[i])){
            cout<<p[i]<<endl;
            return 0;
        }
    }
}