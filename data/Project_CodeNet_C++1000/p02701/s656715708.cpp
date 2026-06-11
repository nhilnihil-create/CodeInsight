#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  int N;
  string S[200000];
  
  cin >> N;
  
  for(int i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  
  sort(S, S+N);
  
  int total = 1;
  
  for(int i = 1; i < N; i++)
  {
    if (S[i] != S[i-1])
    {
      total++;
    }
  }
  
  cout << total << endl;
}