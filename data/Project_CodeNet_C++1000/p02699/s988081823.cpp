#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fkn(i, k, n) for (i = k; i < n; i++)
#define ll long long
#define F first;
#define S second;
#define PB(x) push_back(x);
#define MP(x,y) make_pair(x,y);
typedef vector<ll> vll;

bool powerOfTwo(ll x)
{
    return !(x & (x - 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s,w;
    cin>>s>>w;
    s > w ? cout << "safe" : cout<<"unsafe";

}

