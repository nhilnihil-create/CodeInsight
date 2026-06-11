#include <iostream>

using namespace std;

int b[1000000010];

int main()
{
	int n, q, s, t;
	int ans = 0 ;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		b[s]++;
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> t;
		if (b[t] >= 1) ans++;
	}
	cout << ans << endl;
	return (0);
}