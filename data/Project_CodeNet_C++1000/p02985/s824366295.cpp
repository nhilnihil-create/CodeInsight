#include <iostream>
#include <vector>

#define MOD 1000000007
 
using namespace std;

int N, K;
bool f[1000000];
vector<int> e[1000000];

long dfs(int p, int k){
    long ret = 1;
    f[p] = true;

    int t;
    if(k == K) t = K-1;
    else t = K-2;

    for(int i=0; i<e[p].size(); i++){
        if(!f[e[p][i]]){
            ret = (ret % MOD) * dfs(e[p][i], t) % MOD;
            t--;
        }
    }

    return (ret * k) % MOD;
}

int main(){
    cin >> N >> K;

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
    }

    fill(f, f+N, false);

    long ans = dfs(0, K) % MOD;

    cout << ans;

    return 0;
}
