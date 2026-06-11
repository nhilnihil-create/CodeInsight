#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int M,Nmin,Nmax;
    cin >> M >> Nmin >> Nmax;
    while(M){
        vector<int> V(M);
        rep(i,0,M)cin >> V[i];
        int maxd = 0,maxi;
        rep(i,Nmin-1,Nmax){
            if(maxd <= V[i] - V[i+1]){
                maxd = V[i] - V[i + 1];
                maxi = i + 1;
            }
        }
        cout << maxi << endl;
        cin >> M >> Nmin >> Nmax;
    }
}
