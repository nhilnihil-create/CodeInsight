#include <bits/stdc++.h>
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define sz(v) (int)(v).size()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	int diff = a - b;
	if (diff >= c) cout << 0 << '\n';
	else cout << c - diff << '\n';

	return 0;
}
