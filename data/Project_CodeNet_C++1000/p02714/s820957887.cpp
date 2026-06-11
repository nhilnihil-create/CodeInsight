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
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
const ll mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const ll INF = 1000000000;



int main() {
	int n;
	string s;
	cin >> n >> s;
	map<char, int> x;
	x['B'] = 0;
	x['R'] = 1;
	x['G'] = 2;
	llint a[3][4002] = {0};
	rep(i, 0, n) {
		a[0][i + 1] = a[0][i];
		a[1][i + 1] = a[1][i];
		a[2][i + 1] = a[2][i];
		a[x[s[i]]][i+1]++;
	}
	ll ans = 0;
	rep(i, 0, n-3) {
		rep(j, i + 2, n) {
			if (s[i] == s[j])continue;
			int z = 3 - x[s[i]] - x[s[j]];
			ll cnt = a[z][j + 1] - a[z][i];
			if ((j + i) % 2==0&& x[s[(i + j) / 2]] == z)cnt--;
			ans += cnt;
		}
	}
	cout << ans << endl;
    return 0;
}