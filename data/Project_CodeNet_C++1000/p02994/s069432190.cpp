#include<iostream> 
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
//#define _LIBCPP_DEBUG 0
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define all(a) (a).begin(),(a),end()
#define rep(i,n) for (int i = 0; i < (n); ++i)	
//setprecision(16)

void outi(int x) { cout << x << endl;}
void soutl(ll x) { cout << x << endl;}
void outs(string x) { cout << x << endl;}
ll max(ll a, ll b) {
	ll max;
	if (a > b) max = a;
	else max = b;
	return max;
}
ll min(ll a, ll b) {
	ll min;
	if (a < b) min = a;
	else min = b;
	return min;
}
//---------------------------------------------------------------

int main() {
	int n, l;
	cin >> n>> l;

	int r = l + n - 1;
	int eat;

	if (r <= 0) eat = r;
	else if (l >= 0) eat = l;
	else eat = 0;

	int ans = (l+l+n-1)*n/2 - eat;

	outi(ans);
}