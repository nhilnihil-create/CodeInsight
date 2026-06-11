#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long N;
	long long K;
	long long i;
	long long p;


	cin >> N >> K;
	p=0;
	for(i=K;i<=N+1;i++){
		p+=(N-i+1)*i+1;
		p = p % 1000000007;
	}
	cout << p << endl;
	return 0;
}