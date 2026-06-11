#include <bits/stdc++.h>
#define kika "kika"
#define tam 60
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>

using namespace std;

	string c[tam];
	int t[tam];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	string in1;
	int in2;
	for (int i = 0; i < n; ++i)
	{
		cin >> in1 >> in2;
		c[i] = in1;
		t[i] = in2;
	}
	cin >> in1;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (in1 == c[i]) break;
	}
	int suma = 0;
	for (i++; i < n; i++) {
		suma += t[i];
	}
	cout << suma << "\n";
	return 0;
}