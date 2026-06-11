#include<bits/stdc++.h>
using namespace std;

int sum(int a)
{
    if(a==1) return 300000;
    if(a==2) return 200000;
    if(a==3) return 100000;
    return 0;

}
void solve()
{
  int x, y;
  cin>>x>>y;
  if(x==1 && y==1)
  {
     cout<< 1000000;
     return;
  }

  int res = sum(x)+sum(y);
  cout<<res<<endl;
}
int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();

    }
return 0;
}
