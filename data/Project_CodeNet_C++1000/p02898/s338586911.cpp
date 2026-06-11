#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "\n********************************************\n"
#define fast  ios_base::sync_with_stdio(false), cin.tie(NULL)
int main(int argc, char const *argv[])
{
    fast;
    ll n, k, ans = 0;
    cin >> n >> k;
    while (n --)
    {
    	ll num;
    	cin >> num;
    	ans += (num >= k);
    }
    cout << ans;
    return 0;
}