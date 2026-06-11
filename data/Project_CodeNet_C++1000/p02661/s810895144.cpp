#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long ll;
typedef unsigned long long ull;

typedef V<int> vi;
typedef V<ll> vll;
typedef V<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define f(i,a) for(int i = 0 ; i < a ; i++)
#define fll(i,a) for(ll i = 0 ; i < a ;i++)
#define forab(i,a,b) for(int i = a ; i < b ; i++)
#define prec(x) cout<<fixed<<setprecision(x)
#define ff first
#define ss second

#define pb push_back
#define mp make_pair
#define numberofdigits(x) floor(log10(x)) + 1

void solve()
{
	int n;
	cin >> n;

	int a[n] , b[n];

	for (int i = 0 ; i < n ; i++)
		cin >> a[i] >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	int  m1 = (n & 1) ? a[(n) / 2] : (a[n / 2] + a[n / 2 - 1]) ;
	int  m2 = (n & 1) ? b[(n) / 2] : (b[n / 2] + b[n / 2 - 1]) ;

	cout << (abs(m2 - m1) + 1) << "\n";


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	//cin>>t;

	while (t--)
	{
		solve();
	}

	return 0;
}



