#include<iostream>
#include<cmath>

using namespace std;

int dp[300000] = {0};//0:未定 1:素数である 2:素数でない


bool isSosu(int n){
  bool res = true;
  if(dp[n] == 1){
    res = true;
  }else if(dp[n] == 2){
    res = false;
  }else {
    if(n%2==0 && n!=2){
      res = false;
    }else{
      for(int i=2;i<=sqrt(n);i++){
	if(n%i==0){
	  res = false;
	  break;
	}
      }
    }

    dp[n] = res;
  }

  return res;
}

int solv(int f,int t){
  int res = 0;
  for(int i=f+1;i<=t;i++){
    if(isSosu(i))
      res++;
  }

  return res;
}

int main(){
  int n;
  cin>>n;
  while(n!=0){
    cout<<solv(n,n*2)<<endl;

    cin>>n;
  }

  return 0;

}