#include<iostream>
using namespace std;
int main(){
	long long n; cin >> n;
	long long cnt = 0;
	if (n == 2) { cout << 1 << endl; return 0; }
	for (long long i = 1; i*i <= n-1; i++) {
		if (!((n-1) % i)){
          cnt += 2;
		  if ((n-1) / i == i) cnt--;
        }
	}
	cnt--;
    cnt++;
	for (long long i = 2; i*i <= n; i++) {
		if (n % i) continue;
		long long tn = n;
		long long a = n / i;
		while (!(tn%i)) tn /= i;
		if( tn%i == 1 ) cnt++;
		if (a == i) continue;
		tn = n;
		while (!(tn%a)) tn /= a;
		if( tn%a == 1 ) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
