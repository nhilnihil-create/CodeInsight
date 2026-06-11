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

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    n--;
    for(ll i = 1; i * i <= n; i++)
        if(n % i == 0)
        {
            ans++;
            //cout << i << " ";
            if(i * i < n)
            {
                ans++;
                //cout << n / i << " ";
            }
        }
    //cout << endl;
    //cout << ans << endl;
    n++;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ll t = n;
            while(t % i == 0)
                t /= i;
            if(t % i == 1)
            {
                ans++;
                //cout << i << " ";
            }
            if(i * i < n)
            {
                ll t = n;
                ll u = n / i;
                while(t % u == 0)
                    t /= u;
                if(t % u == 1)
                {
                    ans++;
                    //cout << u << " ";
                }
            }
            //cout << endl;
        }
    }
    cout << ans << endl;
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