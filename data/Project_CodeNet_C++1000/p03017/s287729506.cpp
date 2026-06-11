#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int N, A, B, C, D;
	string S;
	cin >> N >> A >> B >> C >> D >> S;
	bool cross = false;
	for (int i = A - 1; i < max(C, D) - 1; i++) {
		if (S[i] == '#' && S[i + 1] == '#') {
			cout << "No" << endl;
			return 0;
		}
	}
	if (D < C) {
		for (int i = B - 2; i <= D - 2; i++) {
			if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;
}