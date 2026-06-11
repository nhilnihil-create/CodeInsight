#include <bits/stdc++.h>
using namespace std;

long long cnt(long long a){
  if(a==1){
    return 1;
  }else{
    return cnt(a/2)*2+1;
  }
}
  

int main() {
  long long HP;
  cin>>HP;
  cout<<cnt(HP);
}