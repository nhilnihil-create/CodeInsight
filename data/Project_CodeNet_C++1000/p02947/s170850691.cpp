#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  char s[10];
  string String[200000];
  
  cin >> N;
  
  for(int j = 0; j < N; j++)
  {
    for(int i = 0; i < 10; i++)
    {  
      cin >> s[i];
    }
    sort(s, s+10);
    String[j] = s;
    //cout << String[j] << endl;
  }
  
  sort(String, String + N);
  
  int itchi = 0;
  long long pair = 0;
  long long total = 0;

  for(int i = 1; i < N+1; i++)
  {
    //cout << String[i] << ' ';
    if (String[i] == String[i-1])
    {
      itchi++;
    }
    else
    {
      //階乗計算
      for(int j = 1; j <= itchi; j++)
      {
        pair += j;
      }
      
      total += pair;
      
      itchi = 0;
      pair = 0;
      
    }
    //cout << total << endl;
  }
  
  cout << total << endl;
}