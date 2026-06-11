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
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const llint INF = 100000000;


int main() {
	int n;
	cin >> n;
	hei(llint) a(n);
	rep(i, 0, n)cin >> a[i];
	llint now = 1000; llint kabu = 0;
	rep(i, 0, n-1) {
		now += kabu * a[i];
		kabu = 0;
		if (a[i] < a[i + 1]) {
			kabu = now / a[i];
			now %= a[i];
		}
	}
	llint ans = a[n - 1] * kabu + now;
	cout << ans << endl;
	return 0;
}
