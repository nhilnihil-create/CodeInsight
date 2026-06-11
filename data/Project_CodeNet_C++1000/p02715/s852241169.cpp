//  __      __       .__           .____________                   __________        __ ________   __                 
// /  \    /  \ ____ |_________  __| _\______   \__ __  ____  _____\______   \__ ___/  |\_____  \ |  | ______  ___.__.
// \   \/\/   _/ __ \|  \_  __ \/ __ | |    |  _|  |  \/ ___\/  ___/|    |  _|  |  \   __/   |   \|  |/ \__  \<   |  |
//  \        /\  ___/|  ||  | \/ /_/ | |    |   |  |  / /_/  \___ \ |    |   |  |  /|  |/    |    |    < / __ \\___  |
//   \__/\  /  \___  |__||__|  \____ | |______  |____/\___  /____  >|______  |____/ |__|\_______  |__|_ (____  / ____|
//        \/       \/               \/        \/     /_____/     \/        \/                   \/     \/    \/\/     

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ff first
#define ss second
#define PI 3.14159265358979323846
#define endl '\n'

using namespace std;

ll pow3(ll a, ll b, ll m)
{
	ll res = 1;
	while(b > 0)
	{
		if(b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans[k + 1];
    ans[k] = 1;
    ll inf = 1e9 + 7;
    for(ll i = k - 1; i > 0; i--)
    {
        ans[i] = pow3(k / i, n, inf);
        for(ll j = 2 * i; j <= k; j += i)
            ans[i] = (ans[i] + inf - ans[j]) % inf;
    }
    ll out = 0;
    for(ll i = 1; i <= k; i++)
        out = (out + i * ans[i]) % inf;
    cout << out << endl;
}

int main()
{
	int q = 1;
	//scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		solve();
	}
	return 0;
}
