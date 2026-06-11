#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll MOD=1000000007;

int main(){
    ll N,K;cin>>N>>K;
    vector<ll>A(N);
    rep(i,N){
        cin>>A[i];
    }
    //整数列1回分の転倒数
    int count=0;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            if(A[i]>A[j]){
                count++;
            }
        }
    }
    //整数列2回以上の場合に現れる転倒数
    int count2=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                count2++;
            }
        }
    }
    ll ans=0;
    ans=ans+(((K)*(K+1)/2)%MOD*count)%MOD;
    ans=ans+(((K)*(K-1)/2)%MOD*count2)%MOD;
    ans=ans%MOD;
    cout<<ans<<endl;
}