#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A,B,H,M;
  cin>>A>>B>>H>>M;
  double pi = 3.14159265358979;
  double k=cos((60*H-11*M)*pi/360);
  cout<<fixed<<setprecision(10);
  cout<<sqrt(A*A+B*B-2*A*B*k)<<endl;
}
  