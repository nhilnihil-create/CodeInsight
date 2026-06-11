#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 29);
ll h, m, n; string s;
const ll MOD= 1000000007;
const ld PI = acos(-1);
ll sum = 0;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n; vector<int> a(n),x(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }x[0] = sum;
    for (int i = 1; i < n; i += 2) {
        x[0] -= 2 * a[i];
    }
    req(i, n - 1) {
        x[i] = 2 * a[i - 1] - x[i - 1];
    }
    rep(i, n) cout << x[i] << " ";
    cout << endl;
}