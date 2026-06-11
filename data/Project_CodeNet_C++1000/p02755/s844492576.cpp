#include <bits/stdc++.h>
using namespace std;

int main()
{
  long double a,b;
  cin >> a >> b;
  int ma = a,mb = b;
  
  int ans = -1;
  
  for(int i = 10;i < 1260;i ++){
    int c = i * 0.08;
    int d = i * 0.1;
    if(c == ma && d == mb){ans = i;break;}
  }
  
  
  cout << ans << endl;
}