#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a=1,b=n;
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      a = i;
      b = n/i;
    }
  }
  if(1<=a && a<=9 && 1<=b && b<=9) cout<<"Yes";
  else cout<<"No"<<'\n';
}