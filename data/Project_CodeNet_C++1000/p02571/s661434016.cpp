#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int ans = t.size();
	for(int i = 0; i < (int)s.size() - (int)t.size() + 1; ++i){
		int c = 0;
		for(int j = 0; j < (int)t.size(); ++j){
			if(t[j] != s[i + j]) ++c;
		}
		ans = min(ans, c);
	}
	cout << ans << endl;
	return 0;
}