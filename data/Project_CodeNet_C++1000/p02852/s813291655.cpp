#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
llint gcd(llint a, llint b) {
	if (b > a)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
llint Tow(int m,int n) {//2のn乗
	if (n == 0)return 1;
	llint x = Tow(m,n / 2);
	x *= x;
	if (n % 2 == 1)x *= m;
	return x;
}
ll max(ll a, ll b) {
	if (a < b)return b;
	else return a;
}

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int x = n,y=n;
	hei(int) st;
	for (int i = n; i >= 0; i--) {
		if (s[i] == '0')y = i;
		if (x - i >= m) {
			if (y == x) {
				cout << -1 << endl;
				return 0;
			}
			st.push_back(x - y);
			x = y;
		}
	}
	if (x != y)st.push_back(x - y);
	reverse(st);
	rep(i, 0, st.size()) {
		cout << st[i];
		if (i == st.size() - 1)cout << endl;
		else cout << " ";
	}
	return 0;
}