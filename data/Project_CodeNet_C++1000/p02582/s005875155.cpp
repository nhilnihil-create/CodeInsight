#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin>>s;
    ll r=0;
    ll cnt=0;
   for(ll i=0;i<s.length();i++)
    {
       if(s[i]=='R'){
        r++;
        cnt=max(cnt,r);
      }
       else{
         r=0;
       }
    }
    cout<<cnt;


}
