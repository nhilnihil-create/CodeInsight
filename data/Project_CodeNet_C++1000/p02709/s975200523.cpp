#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_enfants;
	cin >> nb_enfants;
	vector<pair<ll, int> > val(nb_enfants);
	for (int i = 0; i < nb_enfants; ++i)
	{
		cin >> val[i].first;
		val[i].second = i;
	}
	sort(val.rbegin(), val.rend());

	vector<vector<ll> > dp(nb_enfants);
	for (int i(0); i < nb_enfants; ++i)
		dp[i].resize(nb_enfants+1);

	for (int i = 0; i < nb_enfants; ++i)
		for (int gauche(0); gauche <= i; ++gauche)
		{
			dp[i][gauche+1] = val[i].first * (val[i].second - gauche) + (i ? dp[i-1][gauche]:0);
			dp[i][gauche] = max(dp[i][gauche], val[i].first * (nb_enfants - (i - gauche) - 1 - val[i].second) + (i?dp[i-1][gauche]:0));
		}
	ll ans(0);
	for (int i(0); i <= nb_enfants; ++i)
		ans = max(dp[nb_enfants-1][i], ans);
	cout << ans << endl;
}
