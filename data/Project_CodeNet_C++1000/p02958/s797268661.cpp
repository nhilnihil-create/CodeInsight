#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  long long n,i,c=0;
  cin>>n;
  long long m[n];
  vector<long long>v;
  for(i=0;i<n;i++)
  {
    cin>>m[i];
    v.push_back(m[i]);
  }
  sort(m,m+n);
  for(i=0;i<n;i++)
  {
    if(v[i]!=m[i])
    {
      c++;
    }
  }
  if(c==0||c==2)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
  return 0;
}