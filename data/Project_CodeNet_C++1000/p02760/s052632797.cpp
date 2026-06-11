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
// #define pb push_back
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

    vector<vl> vet(3, vl(3));
    vll mapa(101, {-1, -1});
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            ll a;
            cin >> a;
            mapa[a] = {i, j};
        }
    }
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll b;
        cin >> b;
        if(mapa[b] != pll{-1, -1}){
            vet[mapa[b].ff][mapa[b].ss] = 1;
        }
    }
    if((vet[0][0] == 1 && vet[0][1] == 1 && vet[0][2] == 1) || (vet[1][0] == 1 && vet[1][1] == 1 && vet[1][2] == 1) || (vet[2][0] == 1 && vet[2][1] == 1 && vet[2][2] == 1) || (vet[0][0] == 1 && vet[1][0] == 1 && vet[2][0] == 1) || (vet[0][1] == 1 && vet[1][1] == 1 && vet[2][1] == 1) || (vet[0][2] == 1 && vet[1][2] == 1 && vet[2][2] == 1) ||(vet[0][0] == 1 && vet[1][1] == 1 && vet[2][2] == 1) || (vet[0][2] == 1 && vet[1][1] == 1 && vet[2][0] == 1)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}