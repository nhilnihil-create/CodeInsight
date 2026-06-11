#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+5;
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==1){
      cout<<"a"<<endl;
      return 0;
    }
    string ans="";
    while(n){
      
      ans+=('a'+(n-1)%26);

      n=(n-1)/26;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}