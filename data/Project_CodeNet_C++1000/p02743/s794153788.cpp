#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(c-a-b<0) return cout << "No", 0;
	cout << (4ll*a*b < (c-a-b)*1ll*(c-a-b) ? "Yes" : "No");
}
