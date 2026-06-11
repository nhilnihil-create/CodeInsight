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

int max(ll a, ll b) {
	ll max;
	if (a > b) max = a;
	else max = b;
	return max;
}
int min(ll a, ll b) {
	ll min;
	if (a < b) min = a;
	else min = b;
	return min;
}


int main() {
	int n;
	double a[110];

	cin >> n;
	rep(i, n) cin >> a[i];

	double ans = 0;
	double sum = 0;
	rep(i, n) {
		sum += 1 / a[i];
	}

	ans = 1 / sum;
	printf("%.8lf", ans);
}