#include<bits/stdc++.h>
using namespace std;

int main(){
  int K,A,B,count=0;
  cin>>K>>A>>B;
  for(int i=A; i<=B; i++){
    if(i%K==0){
      count++;
    }
  }
  if(count>0){
    cout<<"OK"<<endl;
  }
  else{
    cout<<"NG"<<endl;
  }
}