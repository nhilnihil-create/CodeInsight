#include <iostream>
#include <vector>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
long ans;
int N, K;
vector<int> g[100005];

void bfs(int now, int par){
    int mul;
    if(par == -1) mul = K-1;
    else mul = K-2;
    for(auto next : g[now]){
        if(next == par) continue;
        ans = ans * mul % MOD;
        mul = max(mul-1, 0);
        bfs(next, now);
    }
    return;
}

int main(){
    cin >> N >> K;

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans = K;
    bfs(0, -1);

    cout << ans << endl;
    
    return 0;
}
