#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    while(N){
        vector<int> V(N);
        rep(i,0,N)cin >> V[i];
        sort(V.begin(), V.end());
        int mind = INF;
        rep(i,1,N)mind = min(mind, V[i] - V[i-1]);
        cout << mind << endl;
        cin >> N;
    }
}
