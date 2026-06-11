#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define MAX 10000007

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	ll n, k; cin >> n >> k;
    vi v(n); FOR(i, n) cin >> v[i];
    vi F(n);
    FOR(i, n) cin >> F[i];

    sort(rall(v));
    sort(all(F));

    auto f = [&](ll q){
        ll aux = k;
        for(int i = 0; i < n; i++){
            if(1LL*v[i]*F[i] > q){
                aux -= v[i] - (q)/(F[i]);
            }
        }
        return aux >= 0;
    };


    ll a = -1, b = 1e12+1;
    while(b > a + 1){
        ll q = (a+b)/2;
        if(f(q))
            b = q;
        else 
            a = q;
    }

    cout << b << '\n';

	return 0;
}
