#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     ll n;
     cin>>n;
     map< string, ll > m;
     for(int i=0;i<n;i++)
     {
         string s;
         cin>>s;
         sort( s.begin() ,s.end() );
         m[s] ++;
     }
     ll ans =0;
     auto it = m.begin();
     for(;it!= m.end();it++)
     {
         ll temp = it->second;
         ans += (( temp*(temp-1) )/2);
     }
     cout<<ans;
}