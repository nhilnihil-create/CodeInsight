#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{

  ios_base::sync_with_stdio(false);	
  cin.tie(NULL);
  cout.tie(NULL);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int first=max(a*c,a*d);
  int second=max(b*c,b*d);
  int res=max(first,second);
  cout<<res;
  return 0;
}