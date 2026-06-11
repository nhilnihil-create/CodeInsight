#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int ans[100010];
int main()
{
	string S;
	cin >> S;
	int N = S.size();
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R' && S[i + 1] == 'L') {
			ans[i]++;
			ans[i + 1]++;
			for (int j = i - 1; j >= 0; j--) {
				if (S[j] == 'L') break;
				if ((i - j) % 2 == 1) ans[i + 1]++;
				else ans[i]++;
			}
			for (int j = i + 2; j < N; j++) {
				if (S[j] == 'R') break;
				if ((j - i - 1) % 2 == 1) ans[i]++;
				else ans[i + 1]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
