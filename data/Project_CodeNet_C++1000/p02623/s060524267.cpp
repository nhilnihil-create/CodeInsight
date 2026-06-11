#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> A(N),B(M);
    rep(i,N) cin >> A.at(i);
    rep(i,M) cin >> B.at(i);
    vector<ll> SA(N+1),SB(M+1);
    rep(i,N) SA.at(i+1) = SA.at(i)+A.at(i);
    rep(i,M) SB.at(i+1) = SB.at(i)+B.at(i);
    int ans=0,j=M;
    rep(i,N+1) {
        if(SA.at(i)>K) break;
        while(SB.at(j)>K-SA.at(i)) j--;
    ans=max(ans,i+j);
    }
    cout << ans << endl;
    return 0;
}