#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    cin>>N;
    vector<long long> A(N);
    rep(i,N){
        cin>>A[i];
    }
    vector<long long> Sum(N+1);
    Sum[0]=0;
    rep(i,N){
        Sum[i+1]=Sum[i]+A[i];
    }
    //総和から累積和を引いて、累積和との差をメモる。
    //それの最小が答え
    long long ans=INF;
    rep(i,N){
        ans = min(ans,abs((Sum[N]-Sum[i])-Sum[i]));
    }
    cout << ans << endl;
    return 0;
}