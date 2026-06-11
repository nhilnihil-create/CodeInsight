#include<iostream>
using namespace std;

int main()
{
  int cnt = 0;
  string S, T;
  cin >> S >> T;
  for(int i=0; i<S.size(); i++)
  {
    if(S[i] == T[i])
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}