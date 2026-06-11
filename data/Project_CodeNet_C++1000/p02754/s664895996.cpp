#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,N;
  cin>>N>>A>>B;
  long long a,b,c;
  a=N/(A+B);
  b=N%(A+B);
  c=min(b,A);
  cout<<a*A+c<<endl;
}