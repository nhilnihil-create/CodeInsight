#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    unordered_set<int> us;
    rep(i,4){
        us.insert(s[i]);
    }
    if(us.size() == 2 && count(s.begin(), s.end(), s[0]) == 2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
