#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  if(N <= 9)
  {
    if(N == 2 || N == 4 || N ==5 || N == 7 || N == 9)
    {
      cout << "hon" << endl;
    }if(N == 0 || N == 1 || N == 6 || N == 8)
    {
      cout << "pon" << endl;
    }
    if( N == 3)
    {
      cout << "bon" << endl;
    }
    
  }
  if(N >= 10 && N <= 99)
  {
    N = N % 10;
    if(N == 2 || N == 4 || N ==5 || N == 7 || N == 9)
    {
      cout << "hon" << endl;
    }if(N == 0 || N == 1 || N == 6 || N == 8)
    {
      cout << "pon" << endl;
    }
    if( N == 3)
    {
      cout << "bon" << endl;
    }
    
  }
  if(N >= 100 && N <= 999)
  {
    N = N % 100;
    N = N % 10;
    if(N == 2 || N == 4 || N ==5 || N == 7 || N == 9)
    {
      cout << "hon" << endl;
    }if(N == 0 || N == 1 || N == 6 || N == 8)
    {
      cout << "pon" << endl;
    }
    if( N == 3)
    {
      cout << "bon" << endl;
    }
    
  }
  return 0;
}
