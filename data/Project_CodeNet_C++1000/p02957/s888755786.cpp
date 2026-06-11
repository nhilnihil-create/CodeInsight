#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A,B;
  cin>>A>>B;
  if(abs(A-B)%2==1){
    cout<<"IMPOSSIBLE"<<endl;
  }
  else{
    cout<<min(A,B)+abs(A-B)/2<<endl;
  }
}