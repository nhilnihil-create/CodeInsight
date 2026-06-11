#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int INF = 1e6;
vector<vector<int>> graph(1e5 + 1, vector<int>(0));
vector<int> used(1e5 + 1);

long long add(long long a, long long b) {
    long long res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b) {
    long long res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b) {
    return (((a % mod) * (b % mod)) % mod);
}

long long potolok(long long a, long long b){   // округление вверх для целых
    return (a + b - 1) / b;
}


long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }
    if(x > y){
         return gcd(y, x % y);
    }
    else{
         return gcd(x, y % x);
    }
}

bool cmpr(int x, int y){            // сортировка по абсолютной величине
    if(abs(x) < abs(y)) return true;
    else{
        return false;
    }
}

bool comp(pair<int, int> x, pair<int, int> y){  // сортировка по первой компоненте
    if(x.first < y.first)return true;
    else if(x.first == y.first){
        if(x.second < y.second)return true;
        else return false;
    }
    else{
        return false;
    }
}

int cnt(string &s, string &p, int m, int n){
    if((m == 0 && n == 0) || n == 0){
        return 1;
    }
    if(m == 0){
        return 0;
    }
    if(s[m - 1] == p[n - 1]){
        return cnt(s, p, m - 1, n - 1) + cnt(s, p, m - 1, n);
    }
    else{
        return cnt(s, p, m - 1, n);
    }
}

int div(int n){
    int ans = 0;
    vector<int> used(n + 1, 0);
    for(int i = 1;i <= sqrt(n);i++){
        if(n % i == 0 && (!used[i] && !used[n / i])){
            if(i * i == n){
                ans++;
            }
            else{
                ans += 2;
            }
        }
    }
    return ans;
}

void dfs(int node){
    if(used[node]){
        return;
    }
    used[node] = 1;
    for(auto i : graph[node]){
        dfs(i);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(!used[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans - 1 << endl;
}

int main(){
    int t = 1;
    while(t--){
        solve();
    }
 }
