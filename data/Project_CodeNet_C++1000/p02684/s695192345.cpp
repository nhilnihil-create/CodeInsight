#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

const ll d = 60;
const ll N = 200005;
int to[d][N];

int main(){
    ll n,k;
    cin >> n >> k;
    
    rep(i,n){
        cin >> to[0][i];
        to[0][i]--;
    }
    for(ll i=1; i<d; i++){
        rep(j,n){
            to[i][j] = to[i-1][to[i-1][j]];
        }
    }
    int v = 0;
    for(int i=d-1; i>=0; i--){
        ll l = ll(1)<<i;
        if(k-l>=0){
            k-=l;
            v = to[i][v];
        }
        //if(k == 0) break;
    }
    cout << v+1 << endl;
}