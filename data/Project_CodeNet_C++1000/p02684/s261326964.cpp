#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vi v(n);
    for(auto &z : v)
        cin >> z,--z;
    vector<bool> visited(n, 0);

    int tren = 0;
    while(k > 0)
    {
        if(visited[tren])
            break;
        visited[tren] = 1;
        tren = v[tren];
        //cout << tren+1 << '\n';
        --k;
    }
    //cout << tren+1 << '\n';
    if(k == 0)
    {
        cout << tren+1 << '\n';
        return 0;
    }

    vi put;
    put.pb(tren);
    int ntren = v[tren];

    while(ntren != tren)
    {
        put.pb(ntren);
        ntren = v[ntren];
    }
    //for(auto z : put)
        //cout << z << ' ';

    cout << put[k%sz(put)]+1 << '\n';
}
