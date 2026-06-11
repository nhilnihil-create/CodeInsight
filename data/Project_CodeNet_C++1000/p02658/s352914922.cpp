#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=1;
bool zero=false, minuss=false;

int main(){
	cin >> n;
	for (int i=0;i<n;i++){
		long long a;
		cin >> a;
		if (a==0) zero=true;
		else if (ans<=1000000000000000000/a) ans*=a;
		else minuss=true;
	}
	if (zero) cout << 0 << "\n";
	else if (minuss) cout << -1 << "\n";
	else cout << ans << "\n";
}