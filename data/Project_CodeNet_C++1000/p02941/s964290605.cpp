#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A, B;
queue<ll> Q;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        B.push_back(a);
    }
    for(int i=0;i<N;i++) {
        tmp = B[(N+i-1)%N];
        tmp += B[(i+1)%N];
        if(B[i]>=tmp) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        tmp = B[(N+u-1)%N];
        tmp += B[(u+1)%N];
        ans += (B[u]-A[u])/tmp;
        B[u] -= tmp*((B[u]-A[u])/tmp);
        if(B[(N+u-1)%N]>=B[(N+u-2)%N]+B[u]) {
            Q.push((N+u-1)%N);
        }
        if(B[(u+1)%N]>=B[(u+2)%N]+B[u]) {
            Q.push((u+1)%N);
        }
    }
    for(int i=0;i<N;i++) {
        //cout << A[i] << " " << B[i] << endl;
        if(A[i]!=B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}