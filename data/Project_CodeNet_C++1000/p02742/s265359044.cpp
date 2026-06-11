#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b;
  cin>>a>>b;
  if(a==1||b==1){
    cout<<1<<endl;
  }
  else if(a*b%2==1){
  cout<<a*b/2+1<<endl;
  }
  else{
  cout<<a*b/2<<endl;
  }
}
