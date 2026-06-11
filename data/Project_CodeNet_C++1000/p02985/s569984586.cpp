#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N, K;
const ll mod = 1e9 + 7;
bool used[100010];
vector<int> G[100010];

class prm{
private:
    ll MAX_N;
    ll mod;
    vector<ll> prmt;
public:

    ll exp(ll x, ll y){
        if(y == 0) return 1;

        ll x2 = exp(x, y / 2) % mod;
        x2 = x2 * x2 % mod;
        
        if(y % 2 == 1) x2 = x2 * x % mod;

        return x2;
    }

    prm(ll n = 0, ll m = 0){
        MAX_N = n;
        mod = m;
        prmt.resize(MAX_N + 1);

        vector<ll> fct;
        
        fct.push_back(1);
        fct.resize(MAX_N + 1);
        
        for(ll i = 1; i <= MAX_N; i++){
            fct[i] = fct[i - 1] * i % mod;
        }
        for(int i = 0; i <= MAX_N; i++){
            prmt[i] = fct[MAX_N];
            prmt[i] = exp(fct[MAX_N - i], mod - 2) * prmt[i] % mod;
        }
    }

    ll res(int r){
        return prmt[r];
    }
};

int main(){

    cin >> N >> K;
    if(N == 1){
        cout << K << endl;
        return 0;
    }

    prm p1(K - 2, mod);

    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> node;
    node.push(1);
    used[1] = true;
    
    ll ans = K * (K - 1) % mod;

    while(!node.empty()){

        int n = node.front();
        node.pop();

        if(G[n].size() + 1 > K){
            ans = 0;
            break;
        }

        int cnt = -1;
        for(auto& u : G[n]){
            cnt++;
            if(used[u]) continue;
            used[u] = true;
            node.push(u);
        }

        ans = ans * p1.res(cnt) % mod;
    }
    cout << ans << endl;
    return 0;
}