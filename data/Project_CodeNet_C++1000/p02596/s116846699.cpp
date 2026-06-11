#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	if(k%7==0) k/=7;
	if(__gcd(10,k)!=1) {
		cout<<-1;
		return 0;
	}
	long v=1%k;
	int len=1;
	while (v != 0) {
    v = (10 * v + 1) % k;
    len++;
}
cout<<len;
	return 0;
}