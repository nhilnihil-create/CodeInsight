#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,A,B;
  cin>>N>>A>>B;
  long long X=N%(A+B);
  if(X>=A){
    cout<<N/(A+B)*A+A<<endl;
  }
  else{
    cout<<N/(A+B)*A+X<<endl;
  }
}
