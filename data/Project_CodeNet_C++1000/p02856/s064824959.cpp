#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll ans(ll a){
    if(a<10) return 0;
    ll sum=0,k=0,kk=0;
    while(a>0) sum+=a%10,a/=10,k++;
    rep(i,ll(log10(sum))) kk+=sum/ll(pow(10,i+1))-1;
    return ans(sum)+kk+k-1;
}
int main(){
    ll m,D[200001],C[200001],sum=0,k=0,kk=0;
    cin>>m;
    rep(i,m) cin>>D[i]>>C[i],sum+=D[i]*C[i],k+=C[i];
    rep(i,ll(log10(sum))) kk+=sum/ll(pow(10,i+1))-1;
    cout<<ans(sum)+kk+k-1;
}
