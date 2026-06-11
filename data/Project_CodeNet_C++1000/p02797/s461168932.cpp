#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll n , k , s;
	cin >> n >> k >> s;
	//freopen("output.txt" , "w" , stdout);
	while (k--&& n--) cout << s << " ";
	while (n--) cout << (s == 1e9 ? 1 : s+1) << " ";
}
