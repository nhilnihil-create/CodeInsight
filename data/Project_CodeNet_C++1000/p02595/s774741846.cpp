#include<bits/stdc++.h>
using namespace std;

int n;
long long d;
int ans=0;

int main(){
	cin >> n >> d;
	for (int i=0;i<n;i++){
		long long x, y;
		cin >> x >> y;
		if (x*x+y*y<=d*d) ans++;
	}
	cout << ans << "\n";
}