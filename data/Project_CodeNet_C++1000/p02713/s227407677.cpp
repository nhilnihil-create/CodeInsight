#include <bits/stdc++.h>

using namespace std;

int compute_gcd(int i, int j){
  	int divisor = i, dividend = j, remainder;
  	remainder = dividend % divisor;
  	while (remainder){
    	dividend = divisor;
      	divisor = remainder;
      	remainder = dividend%divisor;
    }
  	return divisor;
}

int main(){
  int n,i,j,k;
  long long int sum = 0;
  cin >> n;
  for (i=1;i<=n;i++){
    for (j=i+1;j<=n;j++){
      for (k=j+1;k<=n;k++){
          sum += 6*compute_gcd(compute_gcd(i,j),k);
      }
    }
  }
  sum += (n*(n+1)/2);
  for (i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
      sum += 6*compute_gcd(i,j);
    }
  }
  cout << sum << endl;
  return 0;
}