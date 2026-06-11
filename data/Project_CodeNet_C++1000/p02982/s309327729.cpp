#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N,D;
    cin>>N>>D;
    vector<vector<int>> A(N, vector<int>(D));
    rep(i,N){
        rep(j,D){
            cin>>A[i][j];
        }
    }
    int ans=0;
    rep(i,N-1){
            for(int k=i; k<N; k++){
                    if(k==i){
                    }
              		else if(k<i){}
                    else{
                        ld Z=0;
                        ll X=0;
                        rep(j,D){
                            Z+=(A[i][j]-A[k][j])*(A[i][j]-A[k][j]);
                            X+=(A[i][j]-A[k][j])*(A[i][j]-A[k][j]);
                        }
                      	Z=ld(sqrt(Z));
                      	X=ll(sqrt(X));
                        if(ld(X)==ld(Z)){
                            ans++;
                        }
                    }
                }
            }
    cout<<ans<<endl;
}
