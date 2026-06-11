#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  set<int>s;
  vector<int>a(n);
  vector<int>c(3);
  for(int i=0;i<n;i++)
  {
    int d;
    cin>>d;
    s.insert(d);
    a[i]=d;
  }
  vector<int>f;
  for(auto x:s)
  {
    f.push_back(x);
  }
  for(int i=0;i<n;i++)
  {
    if(a[i]==f[0])c[0]++;
    if(a[i]==f[1])c[1]++;
    if(a[i]==f[2])c[2]++;
  }
  if(s.size()>3)cout<<"No"<<endl;
  else if(s.size()==1 && f[0]==0)cout<<"Yes"<<endl;
  else if(s.size()==2 && f[0]==0 && c[1]==(2*n)/3 && c[0]==n/3)cout<<"Yes"<<endl;
  else if(s.size()==3 && ((f[0]^f[1])^f[2])==0 && c[0]==n/3 && c[1]==n/3)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  //cout<<s.size()<<endl;
  return 0;
}