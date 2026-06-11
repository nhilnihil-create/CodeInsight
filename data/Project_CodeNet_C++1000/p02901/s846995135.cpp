#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF =ll(1e18)+5;


int main(){
    ll N,M;
    cin >> N >>M;
    vector<int> A(M);
    vector<int> C(M);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >>b;
        int S=0;
        for(int j=0;j<b;j++){
            int  c;
            cin >> c;
            --c;
            S |= (1<<c);
        }
        A[i] = a;
        C[i] = S;
        // cerr <<"S=" << S<<endl;
    }
    ll dp[M+1][(1<<N)];
    for(int i=0;i<M+1;i++){
        for(int bit =0;bit<(1<<N);bit++){
            dp[i][bit] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i=0;i<M;i++){
        // cerr <<"i="<< i<< endl;
        for(int bit=0;bit<(1<<N);bit++){
            dp[i+1][bit] = min(dp[i][bit],dp[i+1][bit]);
            // cerr <<"bit=" <<bit <<endl;
            // cerr <<"bit|C[i]=" <<(bit|C[i]) << endl;
            dp[i+1][bit|C[i]] = min(dp[i][bit|C[i]],dp[i+1][bit|C[i]]);
            dp[i+1][bit|C[i]] = min(dp[i+1][bit|C[i]],dp[i][bit] +A[i]);
            // cerr <<"dp=" << dp[i+1][bit|C[i]]<<endl;
        }
        // cerr << dp[i+1][0] << endl;
    }
    if(dp[M][(1<<N)-1] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[M][(1<<N)-1] << endl;
    return 0;
}
