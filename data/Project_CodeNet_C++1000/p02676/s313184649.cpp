#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

int main()
{
	faster;
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	if(n >= s.size()){
		cout << s << endl;
	}else {
		cout << s.substr(0,n) << "..." << endl;
	}
	return 0;
}