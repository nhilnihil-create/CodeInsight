#include <bits/stdc++.h>
using namespace std;


long long int Exp(long long int exp_n,long long int exp_e, long long exp_mod);


int main(){
  long long int N,K,Max_A=0,O;
  priority_queue<long long int> q;
  cin >> N >> K;
  long long int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
    Max_A = max(Max_A,A[i]);
  }
  long long int X,top=Max_A,btm=0;
  X=(top+btm+1)/2;
  while(top != X){
    O=0;
    for(int i=0;i<N;i++){
      O=O+(A[i]-1)/X;
    }
    if(O>K){
      btm=X;
      X=(top+btm+1)/2;
    }else{
      top=X;
      X=(top+btm+1)/2;
    }
  }
  
  cout << X <<endl;
  
  return 0;
}


long long int Exp(long long int exp_n,long long int exp_e, long long int exp_mod){
  long long int exp_o = 1;
  long long int exp_x=exp_n;
  long long int exp_tmp;
  
  while(0<exp_e){
    exp_tmp = exp_e/2;
    if(exp_e - exp_tmp*2 == 1){
      exp_o = exp_o*exp_x;
      if(exp_o>exp_mod){
        exp_o=exp_o%exp_mod;
      }
    }
    
    exp_x = exp_x*exp_x;
    if(exp_x>exp_mod){
      exp_x=exp_x%exp_mod;
    }
    exp_e = exp_tmp;
  }
  return exp_o;
}
