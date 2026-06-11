#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];


int main() {
    int n,k,s;
    cin >> n >> k >> s;
    if(s == 1000000000){
        for (int i = 0; i < k; ++i) {
            cout << 1000000000 << endl;
        }
        for (int i = 0; i < n-k; ++i) {
            cout << 1 << endl;
        }
    }else{
        for (int i = 0; i < k; ++i) {
            cout << s << endl;
        }
        for (int i = 0; i < n-k; ++i) {
            cout << 1000000000 << endl;
        }
    }
    return 0;
}