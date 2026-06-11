#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,d;
  cin>>n>>d;
  int count=1;
  while(true) {
    if(n>(d*2+1)*count) {
      count++;
    }
    else{
      break;
    }
  }
  cout<<count<<endl;
  return 0;
}
