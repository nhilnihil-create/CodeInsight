#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    int n, m; cin >> n >> m;
    priority_queue<ll> pq;
    rep(i, n){
        int a; cin >> a;
        pq.push(a);
    }
    ll x;
    while(m > 0){
        x = pq.top(); pq.pop();
        pq.push(x / 2);
        m--;
    }
    ll ans = 0;
    while(pq.size()){
        x = pq.top(); pq.pop();
        ans += x;
    }
    cout << ans << endl;
}