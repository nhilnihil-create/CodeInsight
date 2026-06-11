#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> G[3 * n];
    rep(i, m){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        G[s].push_back(n + t);
        G[n + s].push_back(2 * n + t);
        G[2 * n + s].push_back(t);
    }
    int s, t;
    cin >> s >> t;
    // rep(i, 3 * n){
    //     cout << i << " :";
    //     rep(j, G[i].size()){
    //         cout << " " << G[i][j];
    //     }
    //     cout << endl;
    // }
    queue<int> q;
    int length[3 * n];
    rep(i, 3 * n) length[i] = -1;
    int e = s - 1;
    length[e] = 0;
    q.push(e);
    while(true){
        if (q.empty()) {
            cout << -1 << endl;
            return 0;
        }
        
        e = q.front();
        // cout << "::::" << e << " " << length[e] << endl;
        for(int i = 0; i < G[e].size(); i++){
            if (length[G[e][i]] != -1) {
                continue;
            }
            
            if (G[e][i] == t - 1) {
                cout << (length[e] + 1) / 3 << endl;
                return 0;
            }
            q.push(G[e][i]);
            length[G[e][i]] = length[e] + 1;
        }
        q.pop();
        if (length[e] > 3 * n) {
            cout << -1 << endl;
            return 0;
        }
    }
}