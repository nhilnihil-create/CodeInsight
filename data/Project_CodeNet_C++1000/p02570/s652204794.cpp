#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int d, t, s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> d >> t >> s;
	cout << (s * t >= d ? "Yes" : "No");
}