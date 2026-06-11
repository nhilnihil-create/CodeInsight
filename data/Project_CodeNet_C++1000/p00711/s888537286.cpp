#include<iostream>
#include<algorithm>

using namespace std;

char tyle[30][30]={'0'};

int find_tyle(int i,int j){
  if(tyle[i+1][j]=='.'){
    tyle[i+1][j]='a';
    find_tyle(i+1,j);
  }
  if(tyle[i][j+1]=='.'){
    tyle[i][j+1]='a';
    find_tyle(i,j+1);
  }
  if(tyle[i-1][j]=='.'){
    tyle[i-1][j]='a';
    find_tyle(i-1,j);
  }
  if(tyle[i][j-1]=='.'){
    tyle[i][j-1]='a';
    find_tyle(i,j-1);
  }
}

int main(){
  
  int w,h;
  
  while(cin>>w>>h,w){
    int ans=0;
    for(int i=1;i<=h;++i){
      for(int j=1;j<=w;++j){
      cin>>tyle[i][j];
      }
    }
    for(int i=1;i<=h;++i){
      for(int j=1;j<=w;++j){
	if(tyle[i][j]=='@'){
	  find_tyle(i,j);
	  tyle[i][j]='a';
	}
      }
    }
    for(int i=1;i<=h;++i){
      for(int j=1;j<=w;++j){
	if(tyle[i][j]=='a'){
	  ans++;
      }
    }
  }
    cout<<ans<<endl;

   for(int i=0;i<30;++i){
      for(int j=0;j<30;++j){
      tyle[i][j]='0';
      }
    }
    
  }
}