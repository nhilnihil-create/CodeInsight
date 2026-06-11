#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n; cin >> n;
	int a[n+1], b[n+1];
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	bool ok = false;
	for(int i=2; i<n; i++){
		if((a[i] == b[i] && a[i-1] == b[i-1]) && (a[i-2] == b[i-2])) ok = true;
	}
	if(ok) cout << "Yes";
	else cout << "No";

    return 0;
}
