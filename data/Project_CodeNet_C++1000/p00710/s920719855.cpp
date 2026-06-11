#include<iostream>
#include<queue>
using namespace std;
int main(){

  int p,c,n,r,fuda[50];
  queue<int> shuffle;

  while(1){

  cin >>n>>r;
  
  if(n == 0 && r == 0)break;

  for(int i=0 ; i < 50  ; i++){
    fuda[i]=i+1;
  }
  
  for(int i=0 ; i < r ; i++){
    
    cin >>p>>c;
    
    for(int j=n-p+1 ; j < n ; j++){ 
      shuffle.push(fuda[j]);
    }
    for(int j=n-p+1-c ; j < n-p+1; j++){
      shuffle.push(fuda[j]);
    }
    for(int j=n-p+1-c ; j < n ; j++){
     fuda[j] = shuffle.front();
      shuffle.pop();
    }
    
  }
  
  cout << fuda[n-1]<<endl;;
  
  }

  return 0;
}