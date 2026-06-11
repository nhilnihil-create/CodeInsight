#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 
//

using namespace std;

long gcd(long a,long b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}

long lcm( long m, long n ){
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / gcd(m, n)) * n); 
}

int main(){
	long long A, B;
	cin >> A >> B;
	cout << lcm(A, B) << endl;
}