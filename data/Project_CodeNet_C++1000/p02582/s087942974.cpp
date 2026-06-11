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
   string s; cin >> s;
   int ans = 0;
   int cnt =0;
   for(int i = 0; i < 3; i++){
    if(s[i] == 'R')
      cnt++;
    else{
      ans = max(ans, cnt);
      cnt = 0;
    }

   }
   cout << max(ans,cnt) << nl;


}
