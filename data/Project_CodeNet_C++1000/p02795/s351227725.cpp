#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w, n;
	cin >> h;
	cin >> w;
	cin >> n;
	cout << ceil((double) n/max(h,w) );
}