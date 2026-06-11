#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,H,M;
  cin>>A>>B>>H>>M;
  
  H%=12;
  
  double theta=min(abs(30*H-5.5*M),360-abs(30*H-5.5*M));
  
  double rad=theta/180*PI;
  
  double ans=pow(A*A+B*B-2*A*B*cos(rad),0.5);
  
  cout<<fixed<<setprecision(15)<<ans<<endl;
}