#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'S') {
			cnt = 0;
		}
		else
		{
			cnt++;
			if (cnt>ans)
			{
				ans = cnt;
			}
		}
	}

	cout << ans << endl;

	return 0;
}