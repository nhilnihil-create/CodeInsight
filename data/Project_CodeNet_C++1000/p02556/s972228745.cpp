#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].first>>v[i].second;
  vector<int>vf[2];
  for(int i=0;i<n;i++)
  {
    vf[0].push_back(v[i].first + v[i].second);
    vf[1].push_back(v[i].first - v[i].second);
  }
  sort(vf[0].begin(),vf[0].end());
  sort(vf[1].begin(),vf[1].end());
  
  int maxi = INT_MIN;
  maxi = max(maxi,vf[0][0]-vf[0][n-1]);
  maxi = max(maxi,-(vf[0][0]-vf[0][n-1]));
  maxi = max(maxi,-(vf[1][0]-vf[1][n-1]));
  maxi = max(maxi,(vf[1][0]-vf[1][n-1]));
  cout<<maxi<<endl;
  return 0;
}
  
    