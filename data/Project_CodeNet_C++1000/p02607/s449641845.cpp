#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  int A[101];
  
  cin >> N;
  
  for (int i = 1; i <= N; i++)
  {
    cin >> A[i];
  }
  
  int count = 0;
  
  for (int i = 1; i <= N; i++)
  {
    if (i % 2 != 0 && A[i] % 2 != 0)
    {
      count++;
    }
  }
  
  cout << count << endl;
}