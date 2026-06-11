#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  while(cin>>n>>p,n+p!=0){
    int winner=0;
    int stone=p;
    int candidate[n]={0};
    int now=0;
    while(1){
      if(stone==0){
	stone+=candidate[now];
	candidate[now]=0;
      }else{
      candidate[now]++;
      stone--;
      }
     if(candidate[now]==p){
	  winner=now;
	  break;
	}
      if(now==n-1)
	now=0;
      else
	now++;
    }
    cout<<winner<<endl;
  }
  return 0;
}