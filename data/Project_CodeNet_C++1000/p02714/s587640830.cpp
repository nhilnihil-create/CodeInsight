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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        map <int, int> m;
        for(int j = i; j < n; j++)
        {
            if(s[i] != s[j])
            {
                int x = 'R' + 'G' + 'B' - s[i] - s[j];
                ans += m[x];
                int k = 2 * j - i;
                //cout << i << "," << j << "," << k << "-";
                if(k > j && k < n && s[k] == x)
                    ans--;
            }
            m[s[j]]++;
            //cout << ans << ' ';
        }
        //cout << endl;
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