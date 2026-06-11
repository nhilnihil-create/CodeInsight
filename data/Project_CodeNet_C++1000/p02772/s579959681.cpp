#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll N;
    cin >> N;
    rep(i, N){
        ll a;
        cin >> a;
        if(a % 2 == 0){
            if(a % 3 != 0 && a % 5 != 0){
                cout << "DENIED";
                return 0;
            }
        }
    }
    cout << "APPROVED";
}