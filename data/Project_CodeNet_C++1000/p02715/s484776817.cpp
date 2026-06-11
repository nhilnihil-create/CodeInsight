#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())

lld mod = 1000000007;

lld binpow(lld x, lld n){
    if(n == 0) return 1;
    if(n == 1) return x;
    lld t = binpow(x,n/2) % mod;
    if(n % 2 == 0) return t * t % mod;
    else return t * t % mod * x % mod;
}

int main() {
    lld N,K;
    cin >> N >> K;
    lld ans = 0;
    lld memo[100001];
    fillnum(memo,-1);
    for (int i = K; i > 0; i--) {
        memo[i] = binpow(K/i,N);
        for (int j = 2*i; j <= K; j+=i) {
            memo[i] = (memo[i] - memo[j] + mod) % mod;            
        }
        ans = (ans + memo[i] * i) % mod;
    }
    cout << ans << endl;
}