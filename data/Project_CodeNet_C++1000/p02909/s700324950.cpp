#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define repB(i, z, n) for(int i = n - 1; i >= z; i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
//#define P pair<int, int>
typedef pair<int, int> P;

int main(){
    string S;
    cin >> S;
    if(S == "Sunny") cout << "Cloudy" << endl;
    if(S == "Cloudy") cout << "Rainy" << endl;
    if(S == "Rainy") cout << "Sunny" << endl;
}