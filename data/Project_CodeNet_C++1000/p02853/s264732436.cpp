#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
const int INF = 1e9;
const ll mod = 1000000007;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b / gcd(a,b);}

int main() {
    int x,y;
    cin >> x >> y;
    vector<int> v = {300000, 200000, 100000};
    if (x == 1 && y == 1) {
        cout << 1000000 << "\n";
    } else {
        cout << v[x-1]+v[y-1] << "\n";
    }

}
