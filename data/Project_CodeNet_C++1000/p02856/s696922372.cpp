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
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = pow(10,15);
int k, x, m, n, h, r, w; ll sum = 0,d = 0,c; string s;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
} 
int main() {
    cin >> m;
    rep(i, m) {
        cin >> k >> c;
        sum += k * c; d += c;
    }d--; sum--;
    cout << d + sum / 9 << endl;
}