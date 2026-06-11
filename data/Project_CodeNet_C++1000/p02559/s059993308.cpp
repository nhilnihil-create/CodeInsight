#include<bits/stdc++.h>
using namespace std;

int N;

void add(int a, int w, vector<long long> &bit) 
{
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
}
long long sum(int a, vector<long long> &bit) {
    long long ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main(void)
{
	cin >> N;
	int q;
	cin >> q;
	vector<long long> BIT(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		add(i, x, BIT);
	}
	for (int i = 0; i < q; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) add(a + 1, b, BIT);
		if (t == 1) cout << sum(b, BIT) - sum(a, BIT) << endl;
	}
}