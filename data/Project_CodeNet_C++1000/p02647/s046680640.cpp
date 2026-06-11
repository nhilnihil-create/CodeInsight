#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K;
    cin >> N >> K;
    K = min(100,K);
    vector<int> A(N+1);
    rep(i,N)cin >> A[i+1];
    
    for(int i=0;i<K;i++){
        vector<ll> L(N+2);
        for(int j=1;j<=N;j++){
            ll l = max(0,j-A[j]);
            ll r = min(N,j+A[j]);
            L[l]++;
            L[r+1]--;
        }
        ll csm = 0;
        for(int j=0;j<=N;j++){
            csm+=L[j];
            A[j]=csm;
        }
    }
    rep(i,N){
        cout << A[i+1] << " ";
    }
    cout << endl;
    return 0;
}