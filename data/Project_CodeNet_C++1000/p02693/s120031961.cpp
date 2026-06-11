#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K,A,B,ans=0;
  cin >> K >> A >> B;
  for (int i = 0; i < B-A+1; i++)
  {
    if((A+i)%K==0)ans=1;
  }
  if(ans==1)cout << "OK";
  else cout << "NG";
    }
