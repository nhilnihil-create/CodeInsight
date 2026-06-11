#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<vector<long long> > G(n);
    vector<pair<long long, long long> > vp;

    for(long long i = 0; i < n-1; i++){
        long long x, y;
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
        vp.push_back(make_pair(x-1, y-1));
    }

    long long maxv = 0;

    for(long long i = 0; i < n; i++){
        maxv = max(maxv, (long long)G[i].size());
    }

    map<pair<long long, long>, long long> I;
    vector<long long> cs(n, 0);

    vector<bool> used(n, false);
    queue<long long> que;
    used[0] = true;

    que.push(0);

    while(!que.empty()){
        long long v = que.front();
        que.pop();

        long long current = 1;

        for(long long i = 0; i < G[v].size(); i++){
            if(used[G[v][i]] == true){
                continue;
            }
            if(current == cs[v]) current++;

            cs[G[v][i]] = I[make_pair(v, G[v][i])] = I[make_pair(G[v][i], v)] = current;
            current++;
            used[G[v][i]] = true;
            que.push(G[v][i]);
        }
    }

    cout << maxv << endl;

    for(long long i = 0; i < n-1; i++){
        cout << I[vp[i]] << endl;
    }
    return 0;
}