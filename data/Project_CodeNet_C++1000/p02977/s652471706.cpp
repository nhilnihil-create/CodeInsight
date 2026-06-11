#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

bool used[222222];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

    ll n;cin >> n;

    int ng = 1;
    REP(i, 30){
        if(n == ng){
            cout << "No" << endl;
            return 0;
        }
        ng *= 2;
    }

    int sum = 0;
    REP(i, n){
        sum ^= (i+1);
    }

    cout << "Yes" << endl;
    int now = 2;
    vector<P> ans;
    REP(i, 30){
        if(sum & (1<<i)){

            if(i == 0){
                ans.EB(3, n + 1);
                used[n+1] = true;
            }
            else if(i == 1){
                if(sum & 4){
                    ans.EB(n + 4, n + 2);
                }
                else {
                    ans.EB(5, n+2);
                }
                used[n+2] = true;
            }
            else {
                ans.EB(1<<i, now);
                ans.EB((1<<i)+1, n+(1<<i));
                used[1<<i] = true;
                used[n+(1<<i)] = true;
                now = (1<<i);
            }
        }
    }

    now = 1;
    for(int i = 2;i <= 2*n;i++){
        if(used[i]){
            continue;
        }
        ans.EB(now, i);
        now = i;
    }

    REP(i, ans.size()){
        cout << ans[i].SE << " " << ans[i].FI << endl;
    }

	return 0;
}
