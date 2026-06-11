#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  int now=0; // 0-close 1-open
  string user[257];
  string visit[257];
  cin>>n;
  for(int i=0;i<n;i++)cin>>user[i];
  cin>>m;
  for(int i=0;i<m;i++)cin>>visit[i];
 
  for(int i=0;i<m;i++){
    int flag=0;
    for(int j=0;j<n;j++){
      if(user[j]==visit[i]){
	if(now==0){
	  cout<<"Opened by "<<visit[i]<<endl;
	  now=1;
	}else{
	  cout<<"Closed by "<<visit[i]<<endl;
	  now=0;
	}
	flag=1;
      }
    }
    if(!flag){
      cout<<"Unknown "<<visit[i]<<endl;
    }
  }
  return 0;
}
    