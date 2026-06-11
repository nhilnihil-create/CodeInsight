#include <bits/stdc++.h>
using namespace std;
long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998626034825342117;
int main(){
  long double A,B,N; cin>>A>>B>>N;N/=A;
  if(A*B/2<=N)cout<<fixed<<setprecision(15)<<atan2(((A*B-N)*2),A*A)*180/PI<<endl;
  else cout<<fixed<<setprecision(15)<<atan2(B*B,N*2)*180/PI<<endl;
}