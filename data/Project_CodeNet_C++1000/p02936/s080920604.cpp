#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n,q;
    cin >> n >> q;
    vector<vector<int>> tree(n, vector<int>(0));
    vector<ll> X(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    rep(i,q){
        int p;
        ll x;
        cin >> p >> x;
        X[p - 1] += x;
    }
    queue<int> qu;
    vector<int> memo(n);
    qu.push(0);
    memo[0] = 1;
    while(!qu.empty()){
        int ci = qu.front();
        qu.pop();
        for(int r: tree[ci]){
            if(memo[r] == 0){
                qu.push(r);
                memo[r] = 1;
                X[r] += X[ci];
            }
        }
    }
    rep(i,n){
        cout << X[i] << " ";
    }
    cout << endl;
    
    return 0;
}
