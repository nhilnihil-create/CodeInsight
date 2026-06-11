#include <bits/stdc++.h>
#define rep(i,x) for(int i=0; i<(int) (x); i++)
#define PI 3.14159265359
using namespace std;
 
int main()
{
  int n; cin>>n;
  n-=(n/1000*1000);
  if (n==0)cout<<"0\n";
  else cout << 1000-n << "\n";
  return 0;
}