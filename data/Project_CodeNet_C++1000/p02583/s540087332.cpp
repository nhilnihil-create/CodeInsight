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
   int n; cin >> n;
   vi v(n);
   ll cnt =0;
   for(int i = 0; i < n; i++) cin >> v[i];

   for(int i = 0; i <n-2; i++){
    for(int j = i+1; j < n-1; j++){
      for(int k = j + 1; k < n; k++){
        int a[3];
        a[0] = v[i];
        a[1] = v[j];
        a[2] = v[k];
        sort(a, a+3);
        if(a[0] + a[1] > a[2] && a[0]!=a[1] && a[1] !=a[2] && a[0] != a[2])
          cnt++;
      }
    }
   }
   cout << cnt <<nl;


}
