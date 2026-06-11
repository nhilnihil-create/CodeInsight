#include<bits/stdc++.h>
#define REP(i,s,n) for(int i=s ; i < n ; i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
int main(){

  int n,Y,M,D;
  int sum_day;
  
  cin >>n;
  
  rep(i,n){
    
    cin >>Y>>M>>D;
    
    sum_day=0;

    while(1){
      
      if(Y==1000 && M==1 && D==1)break;
      
      D++;
      sum_day++;
      
      if(Y%3==0){
	if(D > 20){
	  M++;
	  D=1;
	}
      }else{
	if(M%2 == 0 && D > 19){
	  M++;
	  D=1;
	}else if(M%2 != 0 && D > 20){
	  M++;
	  D=1;
	}
      }
      
      if(M > 10){
	Y++;
	M=1;
      }
      
    }
    
    cout<<sum_day<<endl;
    
  }
  
  return 0;
}