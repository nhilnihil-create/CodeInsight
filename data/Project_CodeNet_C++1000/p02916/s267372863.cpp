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

	int a[22];
	int b[22];
	int c[22];

	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n - 1) cin >> c[i];

	int sum = 0;
	rep(i, n) {
		sum += b[a[i]-1];
		if (a[i] == a[i+1] - 1) {
			sum += c[a[i]-1];
		}
	}

	cout << sum << endl;
}