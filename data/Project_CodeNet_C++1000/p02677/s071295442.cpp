#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  ld A,B,H,M;
  cin>>A>>B>>H>>M;
   double pi = 3.141592653589793238;
  if(12<=H){
H-=12;
  }
  ld C=H*30+M/2-M*6;
  ld r=360-C;
  if(C<0){
    C*=-1;
  }
 if(r<0){
   C*=-1;
 }
    cout<<setprecision(15)<<fixed<<sqrt(A*A+B*B-2*A*B*cos(C/180*pi))<<endl;
}


