#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second


int main(){
    ll n; cin >> n;
    ll cnt = 9;
    queue<ll> que;
    vector<ll> v;
    for(int i = 1; i < 10; i++) {
        que.push(i);
        v.PB(i);
    }

    while(cnt <= n){
        ll a = que.front();
        ll b = a % 10;
        if(b == 0){
            que.push(a*10);
            que.push(a*10+1);
            v.PB(a*10);
            v.PB(a*10+1);
            cnt += 2;
        }else if(b == 9){
            que.push(a*10+8);
            que.push(a*10+9);
            v.PB(a*10+8);
            v.PB(a*10+9);
            cnt += 2;
        }else{
            que.push(a*10+b-1);
            que.push(a*10+b);
            que.push(a*10+b+1);
            v.PB(a*10+b-1);
            v.PB(a*10+b);
            v.PB(a*10+b+1);
            cnt += 3;
        }
        que.pop();
    }
    cout << v[n-1] << endl;
    return 0;
}