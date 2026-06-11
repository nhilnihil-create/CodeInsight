#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, i, ans = 1;
	cin >> n;
	for (i = 1; i * i <= n-1;i++){
		if((n-1)%i==0){
			if(i>1)
				ans++;
			if(i*i<n-1&&n-1>1)
				ans++;
		}
	}
	for (i = 2; i * i <= n;i++){
		if(n%i==0){
			long long cn = n;
			while(cn%i==0)
				cn /= i;
			if(cn%i==1)
				ans++;
			if(i*i<n){
				cn = n;
				while (cn % (n/i) == 0)
					cn /= (n/i);
				if (cn % (n/i) == 1)
					ans++;
			}
		}
	}
	cout << ans << endl;
}