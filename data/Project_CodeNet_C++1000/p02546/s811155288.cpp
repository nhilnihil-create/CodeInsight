#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	string s;
	cin >> s;
	if(s.back() != 's') cout << s << 's' << '\n';
	else cout << s << "es\n";
	
	return 0;
}

