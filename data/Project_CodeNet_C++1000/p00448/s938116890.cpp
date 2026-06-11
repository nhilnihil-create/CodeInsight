#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,c;
  while(cin >> r >> c,r||c){
    int se[10][10000]={{}};
    int i,j,k;
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){
	cin >> se[i][j];
      }
    }
    int o=0;
    for(i=0;i<1<<r;i++){
      int sum[10000]={};
      for(j=0;j<r;j++){
	if(i>>j&1){
	  for(k=0;k<c;k++){
	    if(se[j][k]==0) sum[k]++;
	  }
	}else{
	  for(k=0;k<c;k++){
	    if(se[j][k]==1) sum[k]++;
	  }
	}
      }
      j=0;
      for(k=0;k<c;k++)
	j+=max(sum[k],r-sum[k]);
      o=max(o,j);
    }
    
    cout << o << endl;
  }
  return 0;
}