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
#define rrep(i,n) for(ll i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MOD = 1e9+7;
int main(void) {
    int n; cin >> n; vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a)); int ans = a[0],sum = a[n-1];
    sum = sum - ans;
    req(i, n - 2)  sum += abs(a[i]);
    cout << sum << endl;
    sum = a[n - 1];
    req(i, n - 2) {
        if (a[i] < 0)cout << sum << " " <<a[i] << endl, sum -= a[i];
        else cout << ans << " " << a[i]<<endl, ans -= a[i];
    }cout << sum << " " << ans << endl;
}