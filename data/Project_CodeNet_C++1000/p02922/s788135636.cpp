#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B;
  cin>>A>>B;
  for(int i=0; i<100; i++){
    if((A-1)*i+1>=B){
      cout<<i<<endl;
      break;
    }
  }
}
