//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REP_REV(i,a,b) for (int i = a; i >= b; i--)
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;

void solve() {
	float n, x, t;
	cin >> n >> x >> t;
	int ans = ceil(n / x) * t;
	cout << ans;
	/*
	int n;
	cin >> n;
	int highest = 7;
	int noHighest = 3;
	int bessie = 7, elsie = 7, mildred = 7;
	int ans = 0;
	bool bessieOn = true, elsieOn = true, mildredOn = true;
	vector<tuple<int, string, int>> records;
	REP(i, 0, n - 1) {
		int day, change;
		string name;
		cin >> day >> name >> change;
		tuple<int, string, int> record = tie(day, name, change);
		records.push_back(record);
	}
	sort(records.begin(), records.end());
	REP(i, 0, n - 1) {
		int currNoHighest = 0;
		int high = highest;
		if (get<1>(records[i]) == "Bessie") bessie += get<2>(records[i]);
		if (get<1>(records[i]) == "Mildred") mildred += get<2>(records[i]);
		if (get<1>(records[i]) == "Elsie") elsie += get<2>(records[i]);
		highest = max(bessie, max(elsie, mildred));

		bool bessieOnNext = bessie == highest;
		bool elsieOnNext = elsie == highest;
		bool mildredOnNext = mildred == highest;
		if (bessieOn != bessieOnNext || elsieOn != elsieOnNext || mildredOn != mildredOnNext) {
			ans++;
		}
		bessieOn = bessieOnNext;
		elsieOn = elsieOnNext;
		mildredOn = mildredOnNext;
	}

	cout << ans;*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("measurement.in", "r", stdin);
	//freopen("measurement.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ll t;
	//cin >> t;
	//while (t--) {
	solve();
	//}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file