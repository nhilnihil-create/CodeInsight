#include <bits/stdc++.h>
using namespace std;

int main() {
long long n,m;
cin >> m >> n;

  
if(m==1||n==1)
{
  cout << 1;
}
 else if((m*n)%2==0)
{
cout << m*n/2;
}
  else
  {
    cout << (m*n+1)/2;
  }
}
