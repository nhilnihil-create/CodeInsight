#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,C,K,ans=0;
  cin >> A >> B >> C >> K;
  if (K<=A)
  {
    cout << K;
  }
  else if (A<K && K<=A+B)
  {
    cout << A;
  }
  else if (A+B<K && K<=A+B+C)
  {
    cout << A + (K-A-B)*(-1);
  }
  else
  {
    cout << A - C;
  }
  
  
  
  
}
