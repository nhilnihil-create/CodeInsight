#include<bits/stdc++.h>

using namespace std;

int main(){
  int K, X;
  cin>> K >> X;
  int maxi = 1000000;
  int  mini = -1000000;
  int left = X +1 - K;
  int right = X -1 + K;
  if(left < mini)
  left = mini ;
  if(right > maxi)
  right = maxi;
  for(int i=left;i<=right;i++){
  	cout<<i<<" "; 
  }
  
  return 0;
}