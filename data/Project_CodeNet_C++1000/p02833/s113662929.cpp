#include<iostream>
using namespace std;
long N,a,b=10;
int main(){
  cin>>N;
  if(N&1){
    cout<<0<<endl;
    return 0;
  }
  while(b<=N){
    a+=N/b;
    b*=5;
  }
  cout<<a<<endl;
}
