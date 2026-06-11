#include <bits/stdc++.h>
#define ll long long
#define sz size
#define pb push_back
#define mper make_pair
#define all(x) x.begin(), x.end()
#define fe first
#define se second
#define erba continue
using namespace std;

const ll MAXN = 1e5 + 100;
ll n, a[MAXN];

map <ll, int> mp;
vector <ll> g;

int main() {

cin >> n;

for(int i = 1; i <= n; ++i) {

    cin >> a[i];
    mp[a[i]]++;
    if(mp[a[i]] == 1) {g.pb(a[i]);}

}

sort(all(g));

if(g.sz() == 1 && g[0] == 0) {cout << "Yes";return 0;}

if(n % 3 != 0) {cout << "No";return 0;}

if(g.sz() == 2 && g[0] == 0 && mp[g[0]] == n / 3) {cout << "Yes";return 0;}

if(g.sz() != 3) {cout << "No"; return 0;}


if(mp[g[0]] == mp[g[1]] && mp[g[0]] == mp[g[2]] && (ll)(g[0] ^ g[2] ^ g[1]) == 0) {cout << "Yes";}
else {cout << "No";}


return 0;
}



