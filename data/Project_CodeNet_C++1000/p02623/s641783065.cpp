// 有點不耐煩會破壞偉大的計劃

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
    long long n, m, k; cin >> n >> m >> k;
    
    vector<long long> A(n + 1), B(m + 1), a(n + 1), b(m + 1);
  	
    for(long long i = 1; i <= n; i++) {
   		cin >> A[i];
   		a[i] = a[i - 1] + A[i];
   	}
    
    for(long long i = 1; i <= m; i++) {
   		cin >> B[i];
   		b[i] = b[i - 1] + B[i];
   	}
   	
   	long long ans = 0;
   	for(long long i = 0; i <= n; i++) {
   		if(a[i] > k) break;
   		long long low = 0, high = m, j = low;
   		while(low <= high) {
   			long long mid = low + (high - low) / 2;
   			if(b[mid] <= k - a[i]) {
   				low = mid + 1;
   				j = mid;
   			}
   			else {
   				high = mid - 1;
   			}
   		}
   		ans = max(ans, i + j);
   	}
   	
   	cout << ans;
   	
    return 0;
}
