#include <iostream>
#include <string>
#include <set>
#define llint long long

using namespace std;

llint n, m;
set<string> S;

int main(void)
{
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++){
		cin >> s;
		S.insert(s);
	}
	
	cin >> m;
	
	bool flag = true;
	for(int i = 1; i <= m; i++){
		cin >> s;
		if(S.count(s)){
			if(flag) cout << "Opened by " << s << endl;
			else cout << "Closed by " << s << endl;
			flag = !flag;
		}
		else cout << "Unknown " << s << endl;
	}
	
	return 0;
}
