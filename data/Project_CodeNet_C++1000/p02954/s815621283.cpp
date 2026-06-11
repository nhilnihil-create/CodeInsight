#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

int main(){
  string S;
  cin>>S;
  int L=S.size();

  vi num(L, 1);
  vb R2L(L, false);
  for(int i=0; i<L-1; i++){
    if(S[i]=='R'){
      if(S[i+1]=='L'){
        R2L[i]=true;
      }else{
        num[i+1]+=num[i];
        num[i]=0;
      }
    }
  }

  for(int i=L-1; i>0; i--){
    if(S[i]=='L'){
      if(S[i-1]=='L'){
        num[i-1]+=num[i];
        num[i]=0;
      }
    }
  }
/*
  for(int x: num){
    cout<<x<<",";
  }cout<<endl;

  for(bool x: R2L){
    cout<<x<<",";
  }cout<<endl;
*/
  for(int i=0; i<L; i++){
    if(R2L[i]){
      int sum = num[i]+num[i+1];
      if(sum%2==0){
        num[i] = num[i+1] = sum/2;
      }else{
        if(num[i]%2==1){
          num[i] = sum/2+1;
          num[i+1] = sum/2;
        }else{
          num[i] = sum/2;
          num[i+1] = sum/2+1;
        }
      }
    }
  }

  for(int x: num){
    cout<<x<<" ";
  }
  cout<<endl;
}