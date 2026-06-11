#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  char A;
  char B;
  int C=1;
  string S;
  cin >> N >> S;
  B = S.at(0);
  for(int i=0; i<S.size() ; i++)
  {
    A = S.at(i);
    if(A!=B)
    {
      C++;
      B=A;
    }
  }
  cout << C << endl;
}
      