#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, M;
long long A[100005];

long long gcd(long long a, long long b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}

long long lcm(long long m, long long n ){
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / gcd(m, n)) * n); 
}

int main(){
	cin >> N >> M;
	rep(i, N) cin >> A[i];

	long long twocount = -1;

	for(long long i = 0; i < N; i++) {
		long long two = 0;
		long long num = A[i]/2;
		while(num%2 == 0) {
			two++;
			num/=2;
		}

		if(twocount != -1 && twocount != two) {
			cout << 0 << endl;
			return 0;
		}
		twocount = two;
	}

	long long L = 1;
	for(long long i = 0; i < N; i++) {
		L = lcm(L, A[i]/2);
	if(L > M) {
		cout << 0 << endl;
		return 0;
	}
	}

	if(L > M) {
		cout << 0 << endl;
		return 0;
	}

	long long num = (M - L)/(2*L) + 1;
	cout << num << endl;



}
