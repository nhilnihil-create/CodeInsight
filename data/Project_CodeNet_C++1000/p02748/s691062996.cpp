#include<bits/stdc++.h>
using namespace std;
int main() {
	int A, B, M; cin >> A >> B >> M;
	int a[A], b[B];
	for(int i = 0; i < A; i++) cin >> a[i];
	for(int i = 0; i < B; i++) cin >> b[i];
	int x[M], y[M], c[M];
	for (int i = 0; i < M; i++)
	{
		cin >> x[i] >> y[i] >> c[i];
		x[i]--; y[i]--;
	}
	int mina = *min_element(a, a + A), minb = *min_element(b, b + B);
	int res = mina + minb;
	for (int i = 0; i < M; i++)
	{
		res = min(res, a[x[i]] + b[y[i]] - c[i]);
	}
	
	cout << res << endl;
	return 0;
}
