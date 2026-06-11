#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;


signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int a,b,c,k;
  cin>>a>>b>>c;
  cin>>k;
  int f=0;
  while(k--)
  {
    if (b<=a)
      b=2*b;
    else if (c<=b)
      c=2*c;
    else{
      f=1;
      break;
    }
  }
  if (f || (b>a && c>b))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
