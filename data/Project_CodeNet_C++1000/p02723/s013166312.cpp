#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-9;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

bool isLeap(int a) {
	if (a % 100 == 0) {
		if (a % 400 == 0) return true;
		else return false;
	} else if (a % 4 == 0) return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	Abra_Ka_Dabra

	string x;
	cin>>x;
	if(x[2]==x[3] && x[4]==x[5]) cout<<"Yes\n";
	else cout<<"No\n";

	return 0;
}
