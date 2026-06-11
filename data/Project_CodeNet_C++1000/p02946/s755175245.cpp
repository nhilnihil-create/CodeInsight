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
	int k, x;
	cin >> k >> x;

	rep(i, 2 * k - 1) {
		cout << i + x - k + 1 << " ";
	}
	cout << endl;
	
}