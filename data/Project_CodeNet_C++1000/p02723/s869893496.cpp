#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  string s;
  cin>>s;
  bool flag=0;
  if(s[2]==s[3] && s[4]==s[5])
    flag=1;
  if(flag)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}