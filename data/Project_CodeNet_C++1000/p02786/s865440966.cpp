#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t H,A=1;
  cin>>H;
  while(H>0){
    A*=2;
    H/=2;
  }
  cout<<A-1<<endl;
}