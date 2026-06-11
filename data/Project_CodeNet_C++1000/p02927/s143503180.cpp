#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <iomanip>
#include<cmath>
#include<stdio.h>
#include<map>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define sort(s) sort(s.begin(),s.end())
#define r(s) reverse(s.begin(),s.end())
#define please return
constexpr auto AC = 0;
using namespace std;

int main() {
	int a, b;
	int ans = 0;
	cin >> a >> b;
	for (int i = 11; i <= b; i++) {
		int n = i / 10;
		int m = i % 10;
		if (n>1&&m>1&&n * m <= a && n * m > 0)ans++;
	}
	cout << ans << endl;
	please AC;
}