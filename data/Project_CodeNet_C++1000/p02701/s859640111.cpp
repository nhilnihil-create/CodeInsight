#include<bits/stdc++.h>
using namespace std;
using ll=long long int ;
int main()
{
  ll n;
  cin>>n;
  
  set<string>r;
  
  for(int i=0;i<n;++i)
  {
      string s;
      cin>>s;
      r.insert(s);
  }
  cout<<r.size()<<endl;
}