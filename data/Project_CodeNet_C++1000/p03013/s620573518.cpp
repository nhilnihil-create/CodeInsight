#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;
const int mod = 1000000007;

int main(){
    int N, M; cin >> N >> M;
    vector<int> steps(N + 1, 0);
    rep(i, M){
        int m; cin >> m;
        steps[m] = -1;
    }
    
    steps[0] = 1;
    if(steps[1] == -1) steps[1] = 0;
    else steps[1] = steps[0];
    for(int i = 2; i <= N; i++){
        if(steps[i] == -1) steps[i] = 0;
        else steps[i] = steps[i - 1] + steps[i - 2];
        steps[i] %= mod;
    }
    cout << steps[N] << endl;
}