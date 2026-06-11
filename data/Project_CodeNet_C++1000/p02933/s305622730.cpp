#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a;i < b; i++)

int main() {

	int a;
	string s;

	cin >> a >> s;

	if (a >= 3200) cout << s << endl;
	else cout << "red" << endl;

	return 0;
}