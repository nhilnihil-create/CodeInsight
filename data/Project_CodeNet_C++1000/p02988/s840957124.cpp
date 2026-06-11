#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long double ld;
typedef long long int ll;
const ll INF = (1LL << 63);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0; i < n;i++)
const int MAX = 1000000010;
const ll MOD = 1000000007;
int n, m,k,sum = 0,l; string s;
int main() {
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (i == 0 || i == n - 1) continue;
        if (a[i] != max(a[i], max(a[i + 1], a[i - 1])) && a[i] != min(a[i], min(a[i - 1], a[i + 1]))) sum++;
    }cout << sum << endl;
}