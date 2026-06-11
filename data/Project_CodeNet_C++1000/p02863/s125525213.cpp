#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

const ll mod = 1e9+7;
const ll m = 1e9+7;

ll expo_mod(ll x, ll n) //Exponenciação rápida com módulo
{
    if (n == 0)
        return 1;

    ll t = expo_mod(x, n/2); //O resultado já é em módulo

    ll result = (t * t)%mod;

    if (n%2 == 1) //Se n é ímpar
        return (result * (x%mod))%mod; //(a * b) mod m = (a mod m * b mod m) mod m

    return result;
}

int N, T, dp[3005][3005];

vector< pair<int, int> > v;

int knapsack(int i, int t)
{
    if (i >= N) //Não há mais itens
        return 0;

    if (2 * t > 2 * T - 1) //Depois de T - 0.5 min não pode pedir mais
        return 0;

    if (dp[i][t] != -1)
        return dp[i][t];

    int tempo = v[i].first;
    int happiness = v[i].second;

    int take = knapsack(i+1, t+tempo) + happiness;
    int notake = knapsack(i+1, t);

    return dp[i][t] = max(take, notake);
}

int main ()
{
    cin >> N >> T;

    memset(dp, -1, sizeof dp);

    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        v.push_back( {a, b} );
    }

    sort(v.begin(), v.end());

    cout << knapsack(0, 0) << endl;

    return 0;
}
