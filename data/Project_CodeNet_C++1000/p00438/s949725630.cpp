#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int n,m,i,j,k,xmax;
  while(1){
    xmax=0;
    cin >> n >> m;
   
    if(n == 0 && m == 0)break;
    int MP[m+1][n+1];
    /*
    for(i=1;i<=m;i++){
      for(j=1;j<=n;j++){
	if(i == 1 || j == 1){
	  MP[i][j]=1;
	}else{
	  MP[i][j]=-1;
	}
      }
    }
    */
 for(i=0;i<=m;i++){
      for(j=0;j<=n;j++){
	MP[i][j]=0;
      }
    }
 MP[1][1]=1;        


    cin >> k;

    int No[k+1][2];
    for(i=0;i<k;i++){
      cin >>No[i][0] >> No[i][1]; 
      MP[No[i][1]][No[i][0]]=-1;
    }

    if(n == 1 && m ==1){
      cout << 1 << endl;
      continue;

    }
    

    for(i=1;i<=m;i++){
      for(j=1;j<=n;j++){
	if(i==1 && j==1)continue;
	if(MP[i][j] == -1){continue;}
	else if(MP[i][j-1] == -1 && MP[i-1][j] == -1)MP[i][j]=0;
	else if(MP[i][j-1] == -1)MP[i][j]=MP[i-1][j];
	else if(MP[i-1][j] == -1)MP[i][j]=MP[i][j-1];
	else{
	  MP[i][j]=MP[i-1][j]+MP[i][j-1];
	  xmax=max(xmax,MP[i][j]);
	}

      }
    }

    /* 
    for(i=1;i<=m;i++){
    for(j=1;j<=n;j++)cout << MP[i][j] << "**" ;
    cout << endl;
    }
    */
    
    cout << xmax << endl;
    
  }
  return 0;
}