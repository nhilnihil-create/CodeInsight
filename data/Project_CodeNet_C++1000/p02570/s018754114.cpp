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
    int d, t, s;
    cin >> d >> t >> s;
    if (d <= t * s) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
} 
