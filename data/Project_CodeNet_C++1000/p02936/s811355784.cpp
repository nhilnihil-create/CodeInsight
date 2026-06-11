#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<long long> > G(200000);
vector<long long> counter(200000 ,0);
void dfs(long long i , long long p){
    for(long long v = 0; v < G[i].size(); v++){
        if(p == G[i][v]){
            continue;
        }
        counter[G[i][v]] += counter[i];
        dfs(G[i][v], i);
    }
    return;
}
int main(){
    long long n ,q;
    cin >> n >> q;

    vector<vector<long long> > children(n);
    
    for(long long i = 0; i < n-1; i++){
        long long a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        
        children[a].push_back(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    
    for(long long i = 0; i < q; i++){
        long long p, x;
        cin >> p >> x;
        p -= 1;
        counter[p] += x;

    }

    /*for(long long i = 0; i < n; i++){
        for(long long j = 0; j < children[i].size(); j++){
            counter[children[i][j]] += counter[i];
        }
    }*/

    dfs(0, -1);

    for(long long i = 0; i < n; i++){
        printf("%lld ", counter[i]);
    }
    printf("\n");

    return 0;
}