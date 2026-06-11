#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, a[200000];
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  
  int block = 0;
  int number = 1;
  
  for(int i = 0; i < N; i++)
  {
    if(a[i] == number)
    {
      number++;
    }
    else
    {
      block++;
    }
  }
  
  if (number == 1){
    cout << -1 << endl;
  }
  else{
    cout << block << endl;
  }
}