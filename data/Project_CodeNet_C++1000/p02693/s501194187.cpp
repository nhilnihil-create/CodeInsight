#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,a,b;
  cin>>k>>a>>b;
  int ans=0;
  ans=b/k*k;
  if(ans>=a){
    cout<<"OK"<<endl;
  }
  else{
    cout<<"NG"<<endl;
  }
}
