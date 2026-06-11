#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

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

ll A, B, C, D;

int main(){
	cin >> A >> B >> C >> D;

	ll CD = lcm(C, D);
	ll ans = B - A + 1;

	ans -= (B/C) - ((A-1)/C);
	ans -= (B/D) - ((A-1)/D);
	ans += (B/CD) - ((A-1)/CD);
	cout << ans << endl;


}