#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int num = 0;
  for(int i = 1; ;i++){
    if( (1000 * i) >= N ){
      num = i;
      break;
    }
  }
  
  cout << (1000 * num) - N << endl;
}