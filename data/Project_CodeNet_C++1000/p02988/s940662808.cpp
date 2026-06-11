#include <bits/stdc++.h>
using namespace std;


int main() {
    
  int n ;
  cin>>n;

  int arr[n],count=0;

  for(int i = 0 ; i < n ; i++)
    cin>>arr[i];
  
  for(int i = 0 ; i <= n-3 ; i++){
    if((arr[i]<arr[i+1] && arr[i+1] < arr[i+2]) ||
        (arr[i]>arr[i+1] && arr[i+1]>arr[i+2])
      ){
        count++ ;
      }
  }

  cout<<count;
    
    
	return 0;
}