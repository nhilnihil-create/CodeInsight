#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll A;
  double B;
  cin>>A>>B;
  ll b=round(B*100);
  cout<<ll(A*b/100)<<endl;
}