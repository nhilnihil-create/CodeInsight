#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	
	int mx = max(h, w);
	cout << (n + mx - 1) / mx  << endl;

}