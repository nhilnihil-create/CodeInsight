#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

void printv(vector<vector<int> > g){
    int si = g.size();
    for (int i = 0; i < si; ++i) {
        for (int j = 0; j < si; ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

void printq(queue<int> que){
    int si = que.size();
    int tmp;
    queue<int> k = que;
    for (int i = 0; i < si; ++i) {
        tmp = k.front();
        cout << tmp << " ";
        k.pop();
    }
    cout << endl;
}

int main() {
    int v, e, s_tmp, t_tmp, tmp;
    cin >> v >> e;
    vector<vector<bool> > g(v, vector<bool> (v,0));
    vector<int> ans;
    vector<int> v_n(v, 0);
    for (int i = 0; i < e; ++i) {
        cin >> s_tmp >> t_tmp;
        g[s_tmp][t_tmp] = 1;
        ++v_n[t_tmp];
    }
    //printv(g);
    queue<int> que;
    for (int i = 0; i < v; ++i) {
        if(v_n[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()){
        //printq(que);
        tmp = que.front();
        que.pop();
        ans.push_back(tmp);
        for (int i = 0; i < v; ++i) {
            if(g[tmp][i] == 1){
                g[tmp][i] = 0;
                --v_n[i];
                if(!v_n[i]) {
                    que.push(i);
                }
            }
        }
    }
    for (int i = 0; i < v-1; ++i) {
        cout << ans[i] << " " << endl;
    }
    cout << ans[v-1] << endl;
    return 0;
}


