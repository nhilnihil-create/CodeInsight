#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int main(){
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if(s == u) cout << a-1 << " " << b << "\n";
    else cout << a << " " << b-1 << "\n";
}