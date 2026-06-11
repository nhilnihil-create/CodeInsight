#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X;
  cin>>X;
  long long SUM=100;
  int Ans=0;
  while(SUM<X){Ans++;SUM+=SUM/100;}
  cout<<Ans<<endl;
}
