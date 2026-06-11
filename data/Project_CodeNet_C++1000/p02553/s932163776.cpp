#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  vector<long long>v;
  v.push_back(a*c);
  v.push_back(a*d);
  v.push_back(b*c);
  v.push_back(b*d);
  sort(v.begin(),v.end(),greater<long long>());
  cout<<v[0];
  
}
