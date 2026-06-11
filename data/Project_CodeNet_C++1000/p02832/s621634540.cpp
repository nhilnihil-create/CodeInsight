#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int dx[] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 };
const int dy[] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 };
#define NN 8010000
#define TC int t;cin>>t;for(int T=1;T<=t;T++)
#define mod 1000000007
#define PI acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
void AIA() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
//cout<<fixed<<setprecision(20);
// freopen("stand.in","r",stdin);
// freopen("stand.out","w",stdout);
bool isprime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return (n!=1);
}
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll rem(int x, int N){
	return (x % N + N) % N;
}
ll nCr(ll n, ll r){
	ll ans = 1;
	ll div = 1; // r! 
	for (ll i = r + 1; i <= n; i++){
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}
ll NpR(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= mod;
	}
	return ans;
}
/*
bool prime[20000010];
void sieve()
{
    int i,j;
    for(i=4;i<=20000000;i+=2)
    {
     	prime[i] = 0;
    }
    for(i = 3; i * i <= 20000000;i+=2)
    {
        if(prime[i] == 1)
        {
            for(j = i * i; j <= 20000000; j += i + i)
            {
                prime[j] = 0;
            }
        }
    }
}*/
/*
 _____________              __                ___        ___       ___________________________     ____        ____
|             |            /\ \              |   |      |   |     |                           |    \   \      /   /
|   __________|           / /\ \             |   |      |   |     |      _____      _____     |     \   \    /   /
|  |                     / /  \ \            |   |      |   |     |     |     |    |     |    |      \   \  /   /
|  |                    / /    \ \           |   |      |   |     |     |     |    |     |    |       \   \/   /
|  |______             / /      \ \          |   |______|   |     |     |     |    |     |    |        \      /
|         |           / /        \ \         |              |     |     |     |    |     |    |         \    /
|   ______|          / /          \ \        |    ______    |     |     |     |    |     |    |          |  |
|  |                / /============\ \       |   |      |   |     |     |     |    |     |    |          |  |
|  |               / /==============\ \      |   |      |   |     |     |     |    |     |    |          |  |
|  |              / /                \ \     |   |      |   |     |     |     |    |     |    |          |  |
|  |             / /                  \ \    |   |      |   |     |     |     |    |     |    |          |  |
|__|            /_/                    \_\   |___|      |___|     |_____|     |____|     |____|          |__|

									<<<<<<<<<< NEVER GIVE UP !! >>>>>>>>>>>
									<<<<<<<<<< YOU CAN DO IT IF YOU WANT !! >>>>>>>>
									<<<<<<<<<< BELIEVE IN YOURSELF !! >>>>>>>>>

*/
int main()
{
	//cout<<fixed<<setprecision(6);
	AIA();
	int n;
	cin>>n;
	vector<int>v(n+1);
	for(int i = 1;i<=n;i++){
		cin >> v[i];
	}
	int c = 1;
	for(int i = 1;i<=n;i++){
		if(v[i] == c){
			c++;
		}
	}
	if(c == 1){
		cout <<"-1";
	}
	else cout <<n-c+1;
	return 0;
}