#include<bits/stdc++.h>
using namespace std;

long long N, K;
int main(){
	cin >> N >> K;
	long long cur = 1;
	long long ans = 0;

	while(N>=cur) {
		cur *= K;
		ans++;
	}
	cout << ans << endl;

}