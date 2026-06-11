#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  unsigned long long int a,b,c;
  long long int k;
  cin>>a>>b>>c;
  k=a+b-c;
  cout<<(k>=0?"No":(k*k>4*a*b?"Yes":"No"));
}