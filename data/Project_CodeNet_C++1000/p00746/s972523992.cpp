#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, n, d;
  int w, h, i;

 
  while(1){
    int k[300][4] = {};
    int wl = 0, wr = 1, hu = 1, hs = 0;

     k[0][0] = 0;
     k[0][1] = 0;
     k[0][2] = 1;
     k[0][3] = 1;

    cin>>N;
    
    if(N == 0) break;
    
    for(i = 1; i < N; i++){
      cin>>n>>d;
      if(d == 0){
	k[i][0] = k[n][0] - 1;
	k[i][1] = k[n][1];
	k[i][3] = k[n][3];
	k[i][2] = k[n][2] - 1;
	if(k[i][0]<= wl) wl = k[i][0];
	
      }else if(d == 2){
	k[i][2] = k[n][2] + 1;
	k[i][0] = k[n][0] + 1;
	k[i][1] = k[n][1];
	k[i][3] = k[n][3];
	if(k[i][2] >= wr) wr = k[i][2];
	
      }else if(d == 1){
	k[i][1] = k[n][1] - 1;
	k[i][3] = k[n][3] - 1;
	k[i][0] = k[n][0];
	k[i][2] = k[n][2];
	if(k[i][1]<= hs) hs = k[i][1];
	
      }else if(d == 3){
	k[i][3] = k[n][3] + 1;
	k[i][1] = k[n][1] + 1;
	k[i][0] = k[n][0];
	k[i][2] = k[n][2];
	if(k[i][3] >= hu) hu = k[i][3];
	
      }
    }

    w = wr - wl;
    h = hu - hs;

    cout<<w<<" "<<h<<endl;;
    
  }

  
  return 0;
}

