#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,t;
  cin>>s>>t;
  int ans=0;
  for(int i=0; i<s.size(); i+=1){
    if(s[i]!=t[i]){ans++;}
  }
  cout<<ans;


  return 0;
}
