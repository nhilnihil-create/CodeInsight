/***** author :  C0d1ngPhenomena *****/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define TestCases int T; cin>>T; while(T--)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define revrep(i,a,b) for(ll i = b-1; i >= a; i--)
#define vll vector<ll>
#define vvll vector < vll >
#define pll pair<ll, ll>
#define vpll vector <pll>
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define alld(c) c.begin(),c.end(),greater<int>()
#define mem(a,val) memset(a,val,sizeof(a))
#define f first
#define s second
#define pb push_back
using namespace std;

bool poss(ll T, ll N, ll K, vll A, vll F)
{
	ll sum = 0;

	rep(i, 0, N)
	{
		if (A[i] * F[i] > T)
		{
			sum += A[i] - T / F[i];
		}
	}

	return sum <= K;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, k;
	cin >> n >> k;
	vll A(n), F(n);

	rep(i, 0, n)
		cin >> A[i];

	rep(i, 0, n)
		cin >> F[i];

	sort(all(A));
	sort(all(F));
	reverse(all(F));

	ll lo = 0, hi = 1000000000010;

	rep(i, 0, 50)
	{

		ll mid = (lo + hi) / 2;
		if (poss(mid, n, k , A, F))
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	if (poss(min(hi, lo), n , k, A, F))
	{
		cout << min(hi, lo) << endl;
	}
	else
	{
		cout << max(hi, lo) << endl;
	}

	return 0;
}


