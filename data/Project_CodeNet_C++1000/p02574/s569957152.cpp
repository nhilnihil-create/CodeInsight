#include <bits/stdc++.h>

#define endl '\n'
#define PB push_back
#define PF push_front
#define MP make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(1e6+2);

    int d = 1;
    for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        if (j == 0) {
            d = a;
        }
        d = __gcd(a, d);
        
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                v[i]++;
            }
            while (a % i == 0) {
                a /= i;
            }
        }
        if (a > 1) {
            v[a]++;
        }
    }
    
    sort(all(v));

    if (v.back() <= 1) {
        cout << "pairwise coprime";
    }
    else if (d == 1) {
        cout << "setwise coprime";
    }
    else {
        cout << "not coprime";
    }
    
    return 0;
} 
