#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define int long long
#define ll unsigned long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
	std::ios::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);

const int Maxn = 100001;
const ld pi = acos(-1);
const int mod = 998244353;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A)
{
	for (auto x : A)
		out << x << " ";
	return out;
}



int32_t main(){IOS
	int n,d,a,bombs=0;	cin>>n>>d>>a;
	vector<ipr> A(n);	fr(i,0,n)	cin>>A[i].ff>>A[i].ss;
	sort(all(A));
	vector<int>x(n), h(n), pre(n);
	fr(i,0,n){
		x[i] = A[i].ff;
		h[i] = A[i].ss;
	}
	pre[0] = 0;
	fr(i,0,n){
		h[i] -= pre[i] * a;
		h[i] = max((int)0, h[i]);
		int pos = x[i] + 2 * d, r = upper_bound(all(x), pos) - x.begin() - 1;
		int temp = ceil((double)h[i] / a);
		pre[i] += temp;
		if (r + 1 < n)
			pre[r + 1] -= temp;
		if(i+1<n)
			pre[i+1] += pre[i];
		bombs += temp;
	}
	cout << bombs << endl;
	return 0;
}
