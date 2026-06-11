#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){

    ll k,m; cin >> k;
    queue<ll> q;
    rep(i,9) q.push(i+1);

    rep(i,k-1){
        ll m = q.front();
        q.pop();

        if(m%10 != 0) q.push(10*m + m%10 -1);
        q.push(10*m + m%10);
        if(m%10 != 9) q.push(10*m + m%10 + 1);
    }

    cout << q.front();


}