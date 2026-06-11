#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B;
  cin>>A>>B;
  if(A==1||B==1){
    cout<<1<<endl;
  }
  else{
    cout<<(A*B+1)/2<<endl;
  }
}