#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  if(N%2==0){
    cout<<0.50000<<endl;
  }
  else{
    cout<<1.0*(N/2+1)/N<<endl;
  }
}
