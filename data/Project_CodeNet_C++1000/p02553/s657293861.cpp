#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
//vector<vector<ll>> data(3, vector<ll>(4));
//vector<ll> data(N);
//str s = to_string(i);
//int i = c - '0'
//sort(data.begin(), data.end());
//reverse(data.begin(), data.end());
//data.erase(unique(data.begin(), data.end()), data.end());
//str.substr(n)//n番以降スライス
//str.substr(n,m)//n番以降m文字スライス
//str.erase(n)//n番以降削除
//str.erase(n,m)//n番以降m文字削除
typedef long long ll;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define PB push_back
using namespace std;

bool judge(ll num, vector<ll> start, vector<ll> end) {
	if (num >= (abs(start.at(0) - end.at(0))+ abs(start.at(1) - end.at(1)))
		&& (num - (abs(start.at(0) - end.at(0)) + abs(start.at(1) - end.at(1)))) % 2 == 0) return true;
	else return false;
}
int main() {
	ll a, b, c, d, xy;
	cin >> a >> b >> c >> d;
	xy = max(max(max(a * c, a * d), b * c), b * d);
	cout << xy << endl;
}