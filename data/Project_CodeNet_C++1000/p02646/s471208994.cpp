#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long double A,B,V,W,T;
  double X;
  cin>>A>>V>>B>>W>>T;
  if(W<V){
    X=abs(A-B)/(V-W);
    if(X<=T){
      cout<<"YES"<<endl;
    }
    else{
    cout<<"NO"<<endl;
    }
  }
  else{
    cout<<"NO"<<endl;
  }
}
