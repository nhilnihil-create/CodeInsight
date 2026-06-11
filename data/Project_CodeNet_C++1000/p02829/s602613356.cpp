#include<bits/stdc++.h>
using namespace std;
int main()

{
  vector<int> v;
  for(int i=1;i<=3;i++) v.push_back(i);
int a,b;
  cin>>a>>b;
  for(int i=0;i<v.size();i++)
  {
  if(v[i]==a || v[i]==b)
  {
   v[i]=0;
  }
  }
  cout<<*max_element(v.begin(),v.end())<<endl;
  
}