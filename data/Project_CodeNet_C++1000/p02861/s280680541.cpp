#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  double sum=0;
  cin>>n;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i).first>>a.at(i).second;
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      sum+=sqrt((a.at(i).first-a.at(j).first)*(a.at(i).first-a.at(j).first)+(a.at(i).second-a.at(j).second)*(a.at(i).second-a.at(j).second));
    }
  }
  double ans=sum*(n-1)/(n*(n-1)/2);
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}