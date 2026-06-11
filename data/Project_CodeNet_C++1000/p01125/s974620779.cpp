#include<iostream>
using namespace std;
int main(){
  while(1){
    int n,m,a,b,d=10,e=10,f=0,map[21][21]={};
    char c;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      map[a][b]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>c>>a;
      if(c=='N'){
	for(int j=0;j<a;j++){
	  e++;
	  if(map[d][e]==1){
	    f++;
	    map[d][e]=0;
	  }
	}
      }
      if(c=='S'){
	for(int j=0;j<a;j++){
	  e--;
	  if(map[d][e]==1){
	    f++;
	    map[d][e]=0;
	  }
	}
      }
      if(c=='E'){
	for(int j=0;j<a;j++){
	  d++;
	  if(map[d][e]==1){
	    f++;
	    map[d][e]=0;
	  }
	}
      }
      if(c=='W'){
	for(int j=0;j<a;j++){
	  d--;
	  if(map[d][e]==1){
	    f++;
	    map[d][e]=0;
	  }
	}
      }
    }
    if(f==n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}