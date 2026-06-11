#include <bits/stdc++.h>
using namespace std;

int main(){
  long long S;
  cin>>S;
  long long A=S%1000000000;
  long long B=S/1000000000;
  if(S==1000000000000000000){
    cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<1000000000<<endl;
    return 0;
  }

  cout<<setprecision(18)<<0<<" "<<0<<" "<<1000000000<<" "<<1<<" "<<1000000000-A<<" "<<B+1<<endl;
  return 0;
}
