#include <bits/stdc++.h>
using namespace std;
int main(void){
  int k;
  int a;
  int b;
  cin>>k>>a>>b;
  if(b/k-(a-1)/k==0){
    cout<<"NG"<<endl;
  }else{
    cout<<"OK"<<endl;
  }
  return 0;
}
