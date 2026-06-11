#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


long gcd(int A, int B) {
	if (A % B == 0) return B;
	return gcd(B,A%B);
}

long lcm(long A, long B) {
	return (A/gcd(A,B))*B;	
}
int main(int argc, char *argv[]) {

	long A,B; cin >> A >> B;
	long C,D; cin >> C >> D;

	long ans = 0;

	ans += (B / C);
	ans -= ((A-1) / C);
	ans += (B / D);
	ans -= ((A-1) / D);

	ans += ((A-1) / lcm(C,D));
	ans -= (B / lcm(C,D));

	cout << (B - A + 1) - ans << endl;

	return 0;
}
