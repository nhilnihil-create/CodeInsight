#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  while( cin >> n >> k,n+k){
    
    int a[n];
    for(int i = 0;i < n;i++){
      cin >> a[i];
    }
    int sum = -500000;
    for(int i = 0;i < n-k+1;i++){
      //cout << i << endl;
      int s = 0;
      for(int j = i;j < i+k;j++){
	s += a[j];
      }
      sum = max(s,sum);
    }
    cout << sum <<  endl;
    
  }
  
}