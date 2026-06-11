#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,A,B;
  cin>>N>>A>>B;
  ll c=N/(A+B)*A;
  ll d=min(N%(A+B),A);
  cout<<c+d<<endl;
}
