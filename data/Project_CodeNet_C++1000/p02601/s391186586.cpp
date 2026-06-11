#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a,b,c,k;cin >> a >> b >> c >> k;
	while(b <= a)b*=2,k--;
	while(c <= b || c <= a)c*=2,k--;
	if(k >= 0)cout << "Yes"; else cout << "No";
	return 0;
}