#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if( n < 2 )return false;

	for(int i=2;i*i<=n;i++)
		if( n%i== 0 )
			return false;

	return true;
}

int main(){
  while(1){
  int n,count=0,s;
  cin >> n;
  if(n==0) break;
  for(int i=n+1; i<=2*n; i++){
	s=0;
/*
	for(int j=1; j<=2*n; j++){
          if(i%j==0){
	    s++;
 	  }
	  if(i<j) break;
	}
	if(s==2) count++;
*/
	if( isPrime( i ) ) count++;
	//cout << a[i][j];
  }
  //cout << s << endl;
  //cout << endl;
  cout << count << endl;
  }
 return 0;
}

