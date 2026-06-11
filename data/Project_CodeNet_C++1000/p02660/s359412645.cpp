#include <bits/stdc++.h>

#define N_Max 200001
#define A_Max 1000001
using namespace std;
const long long INF = 1LL <<60;

int main(void){
  long long k,n;
  long long res=0;
  long long flg,tmp;
  long long i,j;
  long pn2[1000001]={};
  long pn[10000000]={};
  long c_pn=0;
  
  cin>>n;

  for(i=2;i<1000000;i++){
    if(pn2[i]==0){
      for(j=i+i;j<1000000;j+=i){
        pn2[j]=1;
      }
    }
  }
  for(i=2;i<1000000;i++){
    if(pn2[i]==0){
      pn[c_pn]=i;
      //cout<<pn[c_pn]<<endl;
      c_pn++;
    }
  }
  
  //cout<<c_pn<<endl;
  
  for(i=0;pn[i]<=n && i<c_pn;i++){
    tmp=0;
    do{
      if(n%pn[i]==0){
        tmp++;
        n=n/pn[i];
      }
      else{
        break;
      }
    }while(1);
    if(tmp!=0){
	  //cout<<pn[i]<<" "<<tmp<<" "<<n<<endl;
      //cout<<(pow(2.0*double(tmp)+0.25,0.5)-0.5)<<endl;
      res+=long(pow(2*tmp+0.25,0.5)-0.5);
    }
  }
  //cout<<res<<" "<<n<<endl;
  if(n!=1){
    res++;
  }
  cout<<res<<endl;
  
  return 0;
  
}      