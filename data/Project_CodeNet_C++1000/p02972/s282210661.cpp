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
const ll INF = (1<<60);
int k, x, m, n, h, r, w,y,d = 0; ll sum = 0; string s,t;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n; vector<int> a(n+1),b(n+1,0);
    req(i, n) cin >> a[i];
    for (int i = n; i > 0; i--) {
        sum = 0;
        for (int j = i + i; j <= n; j += i) {
            if (b[j]) sum += b[j];
        }
        if (sum % 2 != a[i]) b[i] = 1;
    }
    req(i, n) {
        if (b[i]) d++;
    }cout << d << endl;
    req(i, n) {
        if (b[i]) cout << i << endl;
    }
}