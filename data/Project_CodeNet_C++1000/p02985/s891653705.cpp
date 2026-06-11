#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

ll PP(ll a,ll b) {
    ll ret = 1;
    for(ll i = 0;i < b;i++) {
        ret *= (a - i);
        ret %= MOD;
    }
    return ret;
}

ll N,K;
vector<int> graph[100010];
bool used[100010];
ll ret = 1;

void dfs(int a) {
    ll cnt = 0;
    used[a] = true;
    for(int i = 0;i < graph[a].size();i++) {
        if(used[graph[a].at(i)] == false) {
            cnt++;
            dfs(graph[a].at(i));
        }
    }
    if(a == 0) {
        ret = ret * PP(K - 1,cnt);
        ret %= MOD;
    }
    else {
        ret = ret * PP(K - 2,cnt);
        ret %= MOD;
    }
    return;
}

int main() {
    cin >> N >> K;
    for(int i = 0;i < N - 1;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    used[0] = true;
    dfs(0);
    cout << K * ret % MOD << endl;
}