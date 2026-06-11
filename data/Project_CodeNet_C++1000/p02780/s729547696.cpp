#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
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
using Graph = vector<vector<int>>;
Graph G;
/*------------------------------------------------------------------*/
int main(){
    int n, k; cin >> n >> k;
    vector<double> p(n);
    rep(i, n) cin >> p[i];
    vector<double> p_sum(n + 1);
    p_sum[0] = 0;
    _rep(i, 1, n + 1) p_sum[i] = p_sum[i - 1] + (p[i - 1] + 1) / 2;
    double MAX = 0;
    for(int i = k; i <= n; i++){
        double sum = p_sum[i] - p_sum[i - k];
        MAX = max(sum , MAX);
    }
    cout << setprecision(15) << MAX << endl;
}