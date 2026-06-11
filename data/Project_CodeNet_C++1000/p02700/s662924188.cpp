#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int A;
  int B;
  int C;
  int D;
  int num = 1;
  cin>>A;
  cin>>B;
  cin>>C;
  cin>>D;
  while(A > 0 && C > 0){
    if(num % 2 == 1){
      C = C - B;
    }else if(num % 2 == 0){
      A = A - D;
    }
    num += 1;    
  }
  if(num % 2 == 0){
    cout<<"Yes"<<'\n';
  }else{
    cout<<"No"<<'\n';
  }
}