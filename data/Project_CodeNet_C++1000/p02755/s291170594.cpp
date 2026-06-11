#include <bits/stdc++.h>
using namespace std;

int main() {
  double A,B;
  cin>>A>>B;
  bool f=true;
  double C,D;
  for(int i=1; i<1250; i++){
    C=i*0.08;
    D=i*0.1;
    if(A<=C && C<A+1 && B<=D && D<B+1){
      cout<<i<<endl;
      f=false;
      break;
    }
  }
  if(f) cout<<-1<<endl;
}