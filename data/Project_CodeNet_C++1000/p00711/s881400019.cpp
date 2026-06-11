#include<bits/stdc++.h>
using namespace std;
int main(){
  int mp[21][21];
  int w,h;
  int x[4]={1,-1,0,0};
  int y[4]={0,0,1,-1};
  int m;
  bool b;
  char s;
  int ans;
  while(1){
    cin>>w>>h;
    if(w==0 && h==0) break;
    ans=0;
    for(int i=0;i<21;i++){
      for(int j=0;j<21;j++){
	mp[i][j]=0;
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>>s;
	if(s=='#') mp[i][j]=1;
	else if(s=='@') mp[i][j]=2;
      }
    }
    b=true;
    while(b){
      b=false;
      for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
	  if(mp[i][j]==2){
	    /*for(int k=0;k<4;k++){*/
	      if(mp[i+1][j]==0){
		mp[i+1][j]=2;
		b=true;
	      }
	      if(mp[i-1][j]==0){
		mp[i-1][j]=2;
		b=true;
	      }
	      if(mp[i][j+1]==0){
		mp[i][j+1]=2;
		b=true;
	      }
	      if(mp[i][j-1]==0){
		mp[i][j-1]=2;
		b=true;
	      }
	  }
	}
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	/*cout<<mp[i][j]<<" ";*/
	if(mp[i][j]==2) ans++;
      }
      /* cout<<endl;*/
    }
    cout<<ans<<endl;
  }
  return 0;
}
  
    

