#include <bits/stdc++.h>
#define ll long long int
#define for0(i, n) for (int i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (ll)(n); ++i)
#define forc(i, l, r) for (int i = (ll)(l); i <= (ll)(r); ++i)
#define forr0(i, n) for (int i = (ll)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (ll)(n); i >= 1; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) ll((a).size())
#define mod 1000000007
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

void fast()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool prime[1000001];
void sieve()
{
  memset(prime, true, sizeof(prime));
  prime[1]=false;
  for (int p=2; p*p<=1000000; p++)
  {
    if (prime[p] == true)
    {
        for (int i=p*p; i<=1000000; i += p)
                prime[i] = false;
    }
  }
}
void solve()
{
  ll n;
  cin >> n ;
  for(int i=1;i<=n;i++){
    cout << "ACL" ;

  }
  cout << endl;
}
int main()
{
  fast();
 /** ll t;
  cin >> t;
  ll c=1;
  while(t--){**/
  solve();


return 0;
}
