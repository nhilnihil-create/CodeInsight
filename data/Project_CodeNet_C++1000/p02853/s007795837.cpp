#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b)
{
    if(a==1 && b==1) return 1000000;
    int res = 0;
    if(a==1) res += 300000;
    if(a==2) res += 200000;
    if(a==3) res += 100000;
    if(b==1) res += 300000;
    if(b==2) res += 200000;
    if(b==3) res += 100000;
    return res;

}
void solve()
{
  int x, y;
  cin>>x>>y;
  int res = sum(x,y);
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
