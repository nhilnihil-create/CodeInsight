#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define FastIO ios::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
typedef long long ll;


int main()
{
	FastIO;
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto& i : s) {
		int x = i - 'A';
		x = (x + n) % 26;
		cout << (char)('A' + x);
	}
}
