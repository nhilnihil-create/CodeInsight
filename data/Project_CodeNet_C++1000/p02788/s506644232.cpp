#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vll = vector<pll>;
using ld = long double;
#define ff first
#define ss second
const ld pi = acosl(-1);
const ll prime = 1000000000 + 7;
const ll INF = 1000000000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, d, a;
    cin >> n >> d >> a;
    vll vet1(n);
    vl vet(n+1);
    for(int i = 0; i < n; ++i){
        cin >> vet1[i].ff >> vet1[i].ss;
    }
    sort(vet1.begin(), vet1.end());
    ll aux = 0;
    ll res = 0;
    ll ini = 0, fim = 0;
    while(fim < n){
        // W(2*(d+1) + 1, " ")
        // W(vet1[ini].ff, " ")
        // W(vet1[fim].ff, "\n")
        if(vet1[fim].ff - vet1[ini].ff + 1 <= 2*d + 1){
            fim++;
        } else{
            // W(ini, " | ")
            // W(fim, "\n")
            aux += vet[ini];
            if(vet1[ini].ss - aux > 0){
                ll tmp = (vet1[ini].ss - aux + a-1)/a;
                res += tmp;
                aux += tmp*a;
                vet[fim] -= tmp*a;
            }
            ini++;
        }
    }
    while(ini < n){
        // W(ini, " | ")
        // W(fim, "\n")
        aux += vet[ini];
        if(vet1[ini].ss - aux > 0){
            ll tmp = (vet1[ini].ss - aux + a-1)/a;
            res += tmp;
            aux += tmp*a;
            vet[fim] -= tmp*a;
        }
        ini++;
    }
    cout << res << "\n";

    return 0;
}

/*
10
10 9 7 8 6 5 3 4 2 1
*/
// 0 1 2 3 4 5 6 7 8 9 10
// 0 2 0 0 0 4 0 0 0 2 0 