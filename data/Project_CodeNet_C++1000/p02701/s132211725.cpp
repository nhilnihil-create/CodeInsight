#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
  int n;
  cin>>n;
  set<string> s;
  for(int i=0;i<n;i++)
  {
    string str;
    cin>>str;
    s.insert(str);
  }
    cout<<s.size();
}