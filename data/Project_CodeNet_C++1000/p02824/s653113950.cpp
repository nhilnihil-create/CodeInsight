#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll N, M, V, P;
vector<ll> as, sum;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V >> P;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        as.emplace_back(A);
    }
    sort(as.begin(), as.end());
    ll s = 0;
    for(int i = 0; i < N; ++i){
        s += as[i];
        sum.emplace_back(s);
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        int it = upper_bound(as.begin(), as.end(), as[i] + M) - as.begin() - 1;
        if(it < N - P) continue;
        it = N - P;
        chmax(it, i);
        ll len = it - i;
        ll cap = M * (P + i) + (as[i] + M) * len - (sum[it] - sum[i]);
        if(cap >= V * M) cnt++;
    }
    cout << cnt << endl;
    return 0;
}