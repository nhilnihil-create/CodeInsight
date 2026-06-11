#include <iostream>
using namespace std;
int main () {
	long long int N;
	cin >> N;
	long long int ans=N+1;
	for (long long int i=1; i*i<=N; i++) {
		if (N%i==0) {
			ans=min(ans, ((i-1)+(N/i)-1));
		}	
	}
	cout << ans << endl;
}