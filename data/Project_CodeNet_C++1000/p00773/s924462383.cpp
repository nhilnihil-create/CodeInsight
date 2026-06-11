#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,y,s;
  while(cin>>x>>y>>s,x!=0){
    int res=0;
    for(int i=1;i<=s;i++){
      for(int j=1;j<=s;j++){
	if(int(i*double(x+100)/100)+int(j*double(x+100)/100)==s){
	  res=max(res,int(i*double(y+100)/100)+int(j*double(y+100)/100));
	}
      }
    }
    cout<<res<<endl;
  }
  return 0;
}