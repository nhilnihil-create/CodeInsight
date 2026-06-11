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
    int n;
    cin >> n;
    vector<l_l> ba(n);
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        ba[i] = make_pair(b,a);
    }
    sort(ba.begin(), ba.end());
    ll time = 0;
    rep(i,n){
        time += ba[i].second;
        if(time > ba[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
