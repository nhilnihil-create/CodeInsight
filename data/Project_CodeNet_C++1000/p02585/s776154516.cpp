#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> p(n),c(n);
	rep(i, n){
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) cin >> c[i];

	ll ans = -Inf;
	rep(si,n){
		int x = si;
		ll total = 0;
		vector<int> s;
		while (1)
		{
			x = p[x];
			s.push_back(c[x]);
			total += c[x];
			if (x == si)
				break;
		}
		int l = s.size();
		ll t = 0;
		rep(i,l){
			t += s[i];
			if (i + 1 > k)
				break;
			ll now = t;
			if (total > 0){
				ll e = (k - i - 1) / l;
				now += total * e;
			}
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}