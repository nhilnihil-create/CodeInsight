#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int K,X;
  cin>>K>>X;
  for(long int i=(X-K+1);i<(X+K);i++){
    cout<<i;
    if(i==X+K-1){
      cout<<endl;
    }
    else{
      cout<<" ";
    }
  }
}