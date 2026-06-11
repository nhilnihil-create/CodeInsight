#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <tuple>
#include <numeric>
#include <utility>
#include <climits>
#include <float.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#pragma GCC target ("avx2")

using namespace std;

typedef long long ll;
typedef long double ld;
constexpr ll INF = LLONG_MAX;
constexpr double DINF = DBL_MAX;
constexpr ll mod = 1e9+7;
constexpr double PI = M_PI;

template<typename T>
vector<T> make_v(size_t a){
  	return vector<T>(a);
}
 
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts){
  	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main(){
  	cin.tie(0);
  	cout.tie(0);
  	ios::sync_with_stdio(false);
	
	long long n, a, b;
	cin >> n >> a >> b;
	if((b - a) % 2){
		long long ans = min(a - 1, n - b) + 1;
		ans += (b - a - 1) / 2;
		cout << ans << endl;
	}else{
		cout << (b - a) / 2 << endl;
	}
	return 0;
}
