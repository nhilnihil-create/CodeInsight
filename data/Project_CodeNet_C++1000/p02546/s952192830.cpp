#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	if(s.back() == 's') cout << s << "es\n";
	else cout << s << "s\n";
	return 0;
}