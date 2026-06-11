#include<bits/stdc++.h>
using namespace std;
int main() {
	long long x=0,ans=0,n=100;
    cin >> x;
	while (true) {
		ans++;
		n += n/100;
		if (n >= x) {
			cout << ans << endl;
            return 0;
		}
	}
    return 0;
}
