#include <bits/stdc++.h>
using namespace std;


void solve(int n)
{
  int N = n;
  int count=0;
  string S;
  cin >> S;
  for(int i=0; i<N; i++)
  {
    if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C')
    {
      count++;
    }
  }
  cout << count << endl;
}
  
int main()
{
  int N;
  cin >> N;
  solve(N);
  return 0;
}
  