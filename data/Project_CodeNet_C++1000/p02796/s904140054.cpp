#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using P =  pair<int, int>;
using T = tuple<int, int ,int>;

const int MAX_N = 1e5;
const int MAX_V = 1e9;
int N;
int X[MAX_N], L[MAX_N];

P ps[MAX_N];

int solve(){
    rep(i,N) ps[i] = P(X[i] + L[i], X[i] - L[i]);
    sort(ps, ps + N);
    int cur = -MAX_V;
    int ans = 0;
    rep(i,N){
        if(cur <= ps[i].second){
            ans ++;
            cur = ps[i].first;
        }
    }
    return ans;
}

int main(){
    cin >> N;
    rep(i,N) cin >> X[i] >> L[i];

    int ans = solve();
    printf("%d\n", ans);
    return 0;
}