//
// Created by yamunaku on 2019/09/15.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    int n;
    cin >> n;
    vl a(n);
    ll x=0;
    rep(i,n) cin >> a[i], x^=a[i];
    ll aa=x^((1ll<<61)-1);
    rep(i,n) a[i]&=aa;
    int r=0;
    per(i,61){
        bool ok=false;
        repl(j,r,n){
            if(a[j]&(1ll<<i)){
                swap(a[j],a[r]);
                ok=true;
                break;
            }
        }
        if(ok){
            rep(j,n){
                if(j!=r) if(a[j]&(1ll<<i)){
                    a[j]^=a[r];
                }
            }
            r++;
        }
    }
    ll ans=0;
    rep(i,n){
        ans^=a[i];
    }
    cout << (ans<<1)+x << endl;
    return 0;
}
