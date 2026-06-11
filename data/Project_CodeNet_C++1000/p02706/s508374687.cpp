#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m,sum;
  cin>>n>>m;
  vector<int> d(m);
  for(int i=0;i<m;i++)
  {
    cin>>d.at(i);
  }
  sum=accumulate(d.begin(),d.end(),0);
  if(n-sum>=0)
    cout<<n-sum<<endl;
  else
    cout<<"-1"<<endl;
}
