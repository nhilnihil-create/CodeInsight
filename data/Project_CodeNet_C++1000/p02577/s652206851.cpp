#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    string s;
    cin>>s;
    lli sum=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        sum+=s[i]-'0';
    }   
    if(sum%9==0)
    cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }
}
int main()
{
    int t;
   // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}