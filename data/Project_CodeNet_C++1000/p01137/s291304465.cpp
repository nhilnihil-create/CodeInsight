#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int E;
    cin >> E;
    while(E){
        ll mini = INF;
        rep(i,0,1001)rep(j,0,101){
            ll x = i * i + j * j * j;
            if(x <= E)mini = min(mini, i + j + (E - x));
        }
        cout << mini << endl;
        cin >> E;
    }
}
