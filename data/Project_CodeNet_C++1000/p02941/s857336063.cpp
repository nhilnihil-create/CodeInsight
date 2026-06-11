#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin >> A[i];
    priority_queue<P> Q;
    for(int i=0;i<N;i++){
        cin >> B[i];
        Q.push({B[i],i});
    }
    auto getl = [&](int i){
        return (i-1+N)%N;
    };
    auto getr = [&](int i){
        return (i+1)%N;
    };
    ll ans = 0;
    while(!Q.empty()){
        P now = Q.top(); Q.pop();
        ll sum = B[getl(now.second)]+B[getr(now.second)];
        if(now.first<sum) continue;
        if(now.first%sum>=A[now.second]){
            ans += now.first/sum;
            B[now.second] %= sum;
        }else if((now.first-A[now.second])/sum!=0){
            ans += (now.first-A[now.second])/sum;
            B[now.second] -= (now.first-A[now.second])/sum*sum;
        }else continue;
        if(B[now.second]>A[now.second]) Q.push({B[now.second],now.second});
    }
    for(int i=0;i<N;i++) if(A[i]!=B[i]){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}