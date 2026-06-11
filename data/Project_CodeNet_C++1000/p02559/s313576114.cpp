#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#include<atcoder/all>
using namespace atcoder;

int main(void)
{
    IOS
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    REP(i,n) {
        int a; cin >> a;
        ft.add(i,a);
    }
    REP(i,q) {
        int t; cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            ft.add(p,x);
        } else {
            int l, r;
            cin >> l >> r;
            OUT(ft.sum(l,r))
        }
    }

    return 0;
}