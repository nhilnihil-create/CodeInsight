#include <iostream>

using namespace std;

int main()
{
	int n, m;
	char change[60][2];
	char moji;
	string ans;

	while (cin >> n, n){
		ans = "";

		for (int i = 0; i < n; i++){
			cin >> change[i][0] >> change[i][1];
		}

		cin >> m;

		for (int i = 0; i < m; i++){
			cin >> moji;
			for (int j = 0; j < n; j++){
				if (change[j][0] == moji){
					ans += change[j][1];
					break;
				}
				else if (j == n - 1){
					ans += moji;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}