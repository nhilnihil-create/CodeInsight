#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long A,B;
	cin>>A>>B;
	long long ans=(A*B)/__gcd(A,B);
	cout<<ans<<endl;
	return 0;
}