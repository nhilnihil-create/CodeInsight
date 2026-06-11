#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acosl(-1)
#define ld long double
#define prime (1000000000 + 7)
#define INF 1000000000

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, k;
    ld sum = 0, res = 0;
    cin >> n >> k;
    vector<ld> vet(n);
    for(int i = 0; i < n; ++i){
        ll p;
        cin >> p;
        vet[i] = (p + 1) / 2.0l;
    }
    for(int i = 0; i < n; ++i){
        sum += vet[i];
        if(i >= k){
            sum -= vet[i-k];
        }
        res = max(res, sum);
    }
    cout << setprecision(10) << fixed << res << endl;
   
    return 0;
}
