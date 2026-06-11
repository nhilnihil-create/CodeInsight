#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int K = 0;
  cin >> K ;
  int A,B;
  cin >> A >> B;
  int a = A % K;
  int range = B - A;
  string ans = "NG";
  if(a == 0)
    ans = "OK";
  else if(a + range >= K)
    ans = "OK";
  cout << ans <<endl;
}