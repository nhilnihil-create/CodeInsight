#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans*= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main(){
    ld N,K;
    cin>>N>>K;
    vector<ld>P(N);
    rep(i,N){
        cin>>P[i];
        P[i]=(1+P[i])/2;
    }
    ld ans=0;
    ld a=0;
    rep(i,N-K+1){
        if(i==0){
            rep(i,K){
                a+=P[i];
            }
        }
        else{
            a=a-P[i-1]+P[i+K-1];
        }
        if(ans<a){
            ans=a;;
        }
    }
    cout<<setprecision(10)<<fixed<<ans<<endl;
}
