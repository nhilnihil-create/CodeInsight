#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;
  cin >> n;
  
  vector<long long> a(n+1), b(n);
  for(int i=0; i<n+1; i++){
    cin >> a[i];
  }
  for(int j=0; j<n; j++){
	cin >> b[j];
  }
 
  long long num=0;
  for(int k=0; k<n; k++){
    if(a[k] >= b[k]){
	  num = num + b[k];
      a[k] = a[k]-b[k];
    }
    else if(a[k] < b[k] && b[k]-a[k] <= a[k+1]){
      num = num + b[k];
      a[k+1] = a[k+1] - (b[k]-a[k]);
      a[k] = 0;
    }
    else if(a[k] < b[k] && b[k]-a[k] > a[k+1]){
  	  num = num + a[k] + a[k+1];
      a[k] = 0;
      a[k+1] = 0;
    }
  }
  
  cout << num << endl;
  
}
