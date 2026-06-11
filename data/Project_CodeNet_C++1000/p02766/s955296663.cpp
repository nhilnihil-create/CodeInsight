#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,K;
  int A=0;
  cin >> N >> K;
  while(1)
  {
    A++;
    N=N/K;
    if(N==0)break;
  }
  cout << A << endl;
}