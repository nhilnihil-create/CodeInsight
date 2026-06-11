#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,R;
    cin >> N >> R;
    while(N){
        vector<int> V(N);
        iota(V.rbegin(), V.rend(), 1);
        //for(auto i:V)cout << i << endl;
        rep(i,0,R){
            int p,c;
            cin >> p >> c;
            p--;
            vector<int> tmp(p + c);
            rep(j,0,c){
                tmp[j] = V[j + p];
            }
            rep(j,c,p+c){
                tmp[j] = V[j-c];
            }
            rep(j,0,p+c){
                V[j] = tmp[j];
            }
        }
        cout << V[0] << endl;
        cin >> N >> R;
    }
}
