#include <bits/stdc++.h>

using namespace std;

int check(int x)
{
  if (x==1) return 3e5; else
    if (x==2) return 2e5; else
      if(x==3) return 1e5; else return 0;
}

int main()
{
  int a,b;
  cin >> a >>  b;
  int ans=0;
  ans+=check(a);
  ans+=check(b);
  if (a==1 && b==1) ans+=4e5;
  cout << ans;
  return 0;
}