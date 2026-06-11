#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

#include <atcoder/all>
using namespace atcoder;

int main(){
    int n,q;
    cin >> n >> q;
    fenwick_tree<ll> ft(n);
    rep(i,n){
        int a;
        cin >> a;
        ft.add(i,a);
    }

    while(q--){
        int t;
        cin >> t;
        if(t==0){
            int p,x;
            cin >> p >> x;
            ft.add(p,x);
        }else{
            int l,r;
            cin >> l >> r;
            cout << ft.sum(l,r) << endl;
        }
    }
}