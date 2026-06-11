#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	if (ceil(c / b) <= ceil(a / d))puts("Yes");
	else puts("No");
}




