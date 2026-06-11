#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a; cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a%2==0&&(a%6!=0&&a%10!=0)){
      cout<<"DENIED"<<endl;
      exit(0);
    }
  }
  cout<<"APPROVED"<<endl;
}