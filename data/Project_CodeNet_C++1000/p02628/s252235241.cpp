#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<int> d(n,0);
  for(int i=0; i<n; i++){
    cin>>d[i];
  }
  sort(d.begin(),d.end());
  ll sum=0;
  for(int i=0; i<k; i++){
    sum=sum+d[i];
  }
  cout<<sum;
  return 0;
}