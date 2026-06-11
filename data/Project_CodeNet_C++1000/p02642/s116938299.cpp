//given n integers and an integer m such that n>m then there exits a pair
//(a-b) such that (a-b)%m==0


#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
const ll M=1000000007;
void solve(){
 int n;
 cin>>n;
 int a[n];
 map<int,int>mp;
 for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++;
 int ans=0;
 for(int i=0;i<n;i++){
    int x=a[i];
    bool ok=true;
    if(mp[x]>1)ok=false;
    for(int j=2;j<=sqrt(x)&&ok;j++){
        if(x%j==0&&(mp[j]||mp[x/j])){
           ok=false;
        }
    }
    if(ok)ans++;
 }
 if(mp[1]==1)ans=1;
 if(mp[1]>1)ans=0;
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
