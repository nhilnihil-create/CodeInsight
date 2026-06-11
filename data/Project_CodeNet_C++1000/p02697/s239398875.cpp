#include <bits/stdc++.h>
using namespace std;
int main()
{
 int64_t M,B,N,n,m,i;
  cin >> N >> M;
  m=M/2;
  for(i=1;i<=m;i++)
  {
    cout << i << " " << 2*m+2-i << endl;
  }
  m=(M+1)/2;
  for(i=1;i<=m;i++)
  {
    cout << 2*M+2-i << " " << 2*M-2*m+1+i << endl;
  }
  

  
}

