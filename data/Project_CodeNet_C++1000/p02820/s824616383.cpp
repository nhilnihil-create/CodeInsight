#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll n,k,i,j,ans=0;
    cin>>n>>k;
    ll r,ss,p;
    cin>>r>>ss>>p;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
              if(s[i]==s[i-k] && i>=k){
                    s[i]='A';
              }
              else{
                    if(s[i]=='r')ans+=p;
                    if(s[i]=='s') ans+=r;
                    if(s[i]=='p') ans+=ss;
              }
    }
    cout<<ans;
}
