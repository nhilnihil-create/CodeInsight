#include<bits/stdc++.h>
using namespace std;

int main(){
  int i, j, k;
  int q, w;
  int tempx, tempy, temp2, count;
  int N, M;
  char temp1;
  while(1){
    q = 10; w = 10; count = 0;
    int a[30][30] = {};
    cin>>N;
    if(N == 0) break;
    
    for(i = 0; i < N; i++){
      cin>>tempx>>tempy;
      a[tempx][tempy] = 1;
    }
    cin>>M;
    
    if(a[w][q] == 1)count++;
    
    for(i = 0; i < M; i++){
      cin>>temp1>>temp2;
      if(temp1 == 'N') {
	for(j = 1; j <= temp2; j++){
	  q++;
	  if(a[w][q] == 1){
	    count++;
	    a[w][q] = 0;
	  }
	}
      }else if(temp1 == 'S'){
	for(j = 1; j <= temp2; j++){
	  q--;
	  if(a[w][q] == 1){
	    count++;
	    a[w][q] = 0;
	  }
	}
	
      } else if(temp1 == 'E'){
	for(j = 1; j <= temp2; j++){
	  w++;
	  if(a[w][q] == 1){
	    count++;
	    a[w][q] = 0;
	  }
	}
	
      } else if(temp1 == 'W'){
	for(j = 1; j <= temp2; j++){
	  w--;
	  if(a[w][q] == 1){
	    count++;
	    a[w][q] = 0;
	  }
	  
	}
      }
    }
    
    
    
    if(count == N)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    
  }
  return 0;
}

