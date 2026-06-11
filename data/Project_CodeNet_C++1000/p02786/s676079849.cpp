#include <bits/stdc++.h>
using namespace std;
int main(){
  long long H;
  long long ans_=1;
  cin>>H;
  while(H!=0){
    ans_*=2;
    H=H/2;
  }
  cout<<ans_-1<<endl;
}