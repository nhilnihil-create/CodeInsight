//given n integers and an integer m such that n>m then there exits a pair
//(a-b) such that (a-b)%m==0

#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
const ll M=1000000007;
void solve(){
 ll n,d,ans=0;
 cin>>n>>d;
 for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    if(sqrt(x*x+y*y)<=d)ans++;
 }
 cout<<ans;
}

int main(){
 int t=1;
 //cin>>t;
 while(t--){
        solve();
        cout<<endl;
 }
}
