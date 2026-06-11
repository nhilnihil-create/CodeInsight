//given n integers and an integer m such that n>m then there exits a pair
//(a-b) such that (a-b)%m==0


#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
const ll M=1000000007;
void solve(){
 int x,n;
 cin>>x>>n;
 int a[n],mini=INT_MAX;
 vector<pair<int,int>>tans;
 for(int i=0;i<n;i++)cin>>a[i];
 for(int i=0;i<=101;i++){
    bool ok=true;
    for(int j=0;j<n;j++){
        if(i==a[j])ok=false;
    }
    if(ok){
        if(mini>=abs(i-x)){
            mini=abs(i-x);
            tans.push_back({mini,i});
        }
    }
 }
 int ans=INT_MAX;
 for(auto i:tans){
    if(i.first==mini)
        ans=min(ans,i.second);
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
