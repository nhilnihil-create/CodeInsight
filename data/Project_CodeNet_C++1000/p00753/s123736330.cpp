#include<bits/stdc++.h>
#define REP(i,s,n) for(int i=s ; i < n ; i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int Prime_counter(int n){
  
  int cnt=0;
  bool isPrime;
  
  if(n==1)return 1;
  
  REP(i,n+1,2*n+1){
    isPrime=true;
    REP(j,2,sqrt(i)+1){
      if(i%j==0){
	isPrime=false;
	break;
      }    
    }
    if(isPrime)cnt++;
  } 
  
  return cnt;
}
int main(){
  
  int n;
  
  while(1){
    cin >>n;
    if(n==0)break;
    cout <<Prime_counter(n)<<endl;
  }
  
  return 0;
}