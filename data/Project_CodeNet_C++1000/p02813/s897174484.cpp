#include <bits/stdc++.h>

using namespace std;

#define ll long long 






int main(){
  

  int cnt =0 ;
  int n;
  cin>>n;
  
  vector < int > arr(n);
  
  for(int i =0 ; i < n;i++)
  cin>>arr[i];
  
  do{
	  cnt++;
	  
	  
  }while(next_permutation( arr.begin(),arr.end())) ;
  
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  
  do{
	
	cnt--;  
	  
  }while( next_permutation(arr.begin(), arr.end()));
  



  cout<<abs(cnt) ; 
  
  return 0 ;
}
