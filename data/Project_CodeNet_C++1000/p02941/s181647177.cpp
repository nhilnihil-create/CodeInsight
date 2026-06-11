#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    ll A[N], B[N];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    priority_queue<int> que;
    rep(i, N){
        if(B[(i+1)%N] + B[(i+N-1)%N] < B[i]) que.push(i);
    }
    ll count = 0;
    while(!que.empty()){
        int i = que.top();
        que.pop();
        if(A[i] > B[i]) break;
        elif(A[i] == B[i]) continue;
        int j = (i+1)%N;
        int k = (i+N-1)%N;
        ll sum = B[j] + B[k];
        if(A[i] % sum == B[i] % sum){
            count += (B[i]-A[i])/sum;
            B[i] = A[i];
        }
        else{
            if(B[i] % sum == 0){
                count += (B[i]/sum)-1;
                B[i] = sum;
            }
            else{
                count += B[i]/sum;                
                B[i] %= sum;
            }
        }
        if(B[j] > B[(j+1)%N] + B[i]) que.push(j);
        if(B[k] > B[i] + B[(k+N-1)%N]) que.push(k);
    }
    bool able = true;
    rep(i, N){
        if(A[i] != B[i]) able = false;
    }
    if(able) cout << count << endl;
    else cout << -1 << endl;
}