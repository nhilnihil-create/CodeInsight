#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long N,a;
  int b,c;
  cin>>N;
  a=N/500;
  b=N%500;
  c=b/5;
  cout<<a*1000+c*5<<endl;
}