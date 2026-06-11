#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int pos[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i]-- , pos[a[i]] = i;

	set<int> st;
	st.insert(-1);
	st.insert(n);

	ll res = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		int k = pos[i];

		auto R = st.lower_bound(k);
		auto L = R;
		L--;

		if(*R != n)
		{
			auto tmp = R;
			tmp++;
			res += 1LL * (i + 1) * (*tmp - *R) * (k - *L);
		}
		if(*L != -1)
		{
			auto tmp = L;
			tmp--;
			res += 1LL * (i + 1) * (*R - k) * (*L - *tmp);
		}

		st.insert(k);
	}

	cout << res << endl;
}










 
