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
    int cnt = 0;
    queue <ll> q;
    for(int i = 1; i < 10; i++)
        q.push(i);
    while(true)
    {
        ll x = q.front();
        q.pop();
        cnt++;
        if(cnt == n)
        {
            cout << x << endl;
            return;
        }
        if(x % 10 > 0)
            q.push(x * 10 + x % 10 - 1);
        q.push(x * 10 + x % 10);
        if(x % 10 < 9)
            q.push(x * 10 + x % 10 + 1);
    }
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