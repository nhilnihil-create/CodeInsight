#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  for(int i=1;i<10&&i*i<=n;i++){
    if(n%i==0&&n/i<10) { cout<<"Yes"<<endl; return 0; }
  }
  cout<<"No"<<endl; 
  return 0;
}