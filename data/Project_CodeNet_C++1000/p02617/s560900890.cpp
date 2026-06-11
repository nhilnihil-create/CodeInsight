#include <bits/stdc++.h>
using namespace std;


long long int Exp(long long int exp_n,long long int exp_e, long long exp_mod);


int main(){
  long long int N,O;
  cin >> N;
  O = N*(N+1)*(N+2)/6;
  
  int u,v,U,V;
  for(int i=0;i<N-1;i++){
    cin >> u >> v;
    O = O - min(u,v)*(N-max(u,v)+1);
  }
    
  cout << O <<endl;
  
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
