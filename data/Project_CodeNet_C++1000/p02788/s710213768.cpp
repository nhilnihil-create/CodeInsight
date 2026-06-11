#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MAX_N = 200005;
vector<ll> X,H;
ll bomb[MAX_N];
vector<P> XH;
queue<P> Q;

int main()
{
	ll N,D,A;
	cin >> N >> D >> A;
	rep(i,N)
	{
		ll x,h;
		cin >> x >> h;
		X.push_back(x);
		H.push_back(h);
		XH.push_back(P(x,h));
	}
	sort(X.begin(), X.end());
	sort(XH.begin(), XH.end());
	Q.push(XH[0]);
	rep(i,N-1)
	{
		if (XH[i+1].first <= XH[0].first + 2 * D)
		{
			Q.push(XH[i+1]);
		}
		else
		{
			break;
		}
	}
	ll ans = 0;
	ll temp = 0;
	rep(i,N)
	{
		//cout << bomb[i] << " ";
		temp += bomb[i];
		//cout << temp * A << " " << XH[i].second << " ";
		if (temp * A >= XH[i].second) continue;
		ll b = (XH[i].second - temp * A + A - 1) / A;
		ans += b;
		temp += b;
		bomb[upper_bound(X.begin(), X.end(),XH[i].first+2*D) - X.begin()] -= b;
		//cout << upper_bound(X.begin(), X.end(),XH[i].first+2*D) - X.begin() << endl;
	}
	cout << ans << endl;
	return 0;
}