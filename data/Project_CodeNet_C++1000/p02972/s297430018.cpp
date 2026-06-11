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

vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n; cin >> n;
    vector<ll> a(n),tmp;
    vector<ll> mem(200001,0);
    queue<ll> q;

    rep(i,n) cin >> a[i];

    for(ll i = n; i >= 1; i --){

        if(mem[i]%2 == 1 && a[i-1] == 1){
            continue;
        }else if(mem[i]%2 == 0 && a[i-1] == 0){
            continue;
        }else{
            tmp = enum_divisors(i);
            q.push(i);
            rep(j,tmp.size()){
                mem[tmp[j]] ++;
            }
        }
    }

    cout << q.size() << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}