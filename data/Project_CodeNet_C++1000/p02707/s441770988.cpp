#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
#endif

  int n;
  cin>>n;
  vector<int> v(n+1);
 for(int i=0;i<=n;i++)
 {
   v[i]=0;
 }
  for(int i=0;i<n-1;i++)
  {
    int x;
    cin>>x;
    v[x]++;
  }

  for(int i=1;i<=n;i++)
  {
    cout<<v[i]<<endl;
  }

  return 0;
}