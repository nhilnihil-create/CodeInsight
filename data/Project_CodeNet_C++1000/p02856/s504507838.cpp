#include <bits/stdc++.h>
#define REP(i, x, y) for (ll i = x; i <= y; i++)
#define BIT(t) (1ll << t)
#define PER(i, y, x) for (ll i = y; i >= x; i--)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define SIZE(v) ll(v.size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
using namespace std;
typedef long long ll;
//        ios::sync_with_stdio(false);
//        cin.tie(nullptr);

int main(){
        ll n;
        cin >> n;
        ll keta = 0;
        ll sm = 0;
        REP(i,1,n){
                ll d,c;
                cin >> d >> c;
                keta += c;
                sm += d*c;
        }
        cout << keta - 1 + (sm - 1) / 9 << endl;
}