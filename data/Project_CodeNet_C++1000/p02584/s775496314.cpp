#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> vll;
typedef pair<int, int> vii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define asd cout << "ok" << endl;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define trav(it, m) for(auto it = m.begin(); it!= m.end(); it++)

const char nl = '\n';
const int MX = 2e5 +5;
const int MOD = 1e9 +7;
const int inf = 1e9;
const ll INF = 1e18;
const ld PI = acos((ld)-1);

int fenwick[MX] = {};




int main(){
   ios_base::sync_with_stdio(0); cin.tie(0);
   ll x, k, d;
   cin >> x >> k >> d;
   if(x < 0) x = -x;
   if(k <= x/d){
    cout << (x - d*k) <<nl;
    return 0;
   }

   ll tmp = x/d;
   k -= tmp;
   if(k%2) cout << abs(d-x%d) << nl;
   else cout << abs(x%d) << nl;

}
