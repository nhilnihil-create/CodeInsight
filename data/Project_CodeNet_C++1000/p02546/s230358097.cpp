#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	if(s.back() == 's')
		cout << s+"es";
	else
		cout << s+"s";
}


int main() {
    int t;
    // cin>>t;
	// while(t--)
		solve();
	return 0;

}