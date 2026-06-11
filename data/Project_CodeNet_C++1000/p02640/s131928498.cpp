#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int x, y;
    cin >> x >> y;
    
    for(int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int sum = 2*i +4*j;
            int num = i+j;

            if(sum == y && num == x) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        
    }

    cout << "No" << endl;

    return 0;
}