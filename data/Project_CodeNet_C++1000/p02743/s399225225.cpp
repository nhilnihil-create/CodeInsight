#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  long double A,B,C;
  cin>>A>>B>>C;
  cout<<(A+B+2*sqrt(A*B)<C?"Yes":"No")<<endl;
}