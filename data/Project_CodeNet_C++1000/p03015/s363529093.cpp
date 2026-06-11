//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define mod 1000000007
#define endl '\n'
typedef long long int ll ;
using namespace std;
#define MAX 100003
ll power(ll a, ll b) 
{
    ll res=1LL;
    while(b>0){
        if(b&1LL) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}
string add_one(string s)
{
    s="0"+s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='0') {
            s[i]='1';
            break;
        }
        else s[i]='0';
    }
    return s;
}
int main()
{
    string s;
     cin>>s;
     s=add_one(s);
     
     ll cnt=0;
     ll ans=0;
     for(int i=0;i<s.size();i++){
         if(s[i]=='1') {
             ll left=s.size()-i-1;
             ll val=(power(2,cnt) * power(3,left))%mod ;
             ans=(ans+val)%mod;
             cnt++;
         }
     }
     ans%=mod;
     cout<<(ans)%mod<<endl;
}