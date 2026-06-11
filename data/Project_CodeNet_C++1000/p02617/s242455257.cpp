#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
  ll n,i,u,v,res;
  cin >> n;
  res=n*(n+1)*(n+2)/6;
  for(i=0;i<n-1;i++){
    cin >> u >> v;
    if(u<v)
      res-=u*(n-v+1);
    else
      res-=v*(n-u+1);
  }
  cout << res << endl;
  return 0;
}