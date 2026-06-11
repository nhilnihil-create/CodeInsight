#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
       string s;
       ll n; cin>>n;
       cin>>s;
       ll r=0,cnt=0;
       for(ll i=2; i<s.size(); i++){
        if(s[i]=='C' && s[i-1]=='B' && s[i-2]=='A')cnt++;
       }
       cout<<cnt<<endl;


}