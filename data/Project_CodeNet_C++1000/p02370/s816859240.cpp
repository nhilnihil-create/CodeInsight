#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, E;
vector<int> g[10000];
vector<int> out;
char col[10000];

void toposort(int s) {
    stack<int> chain;
    col[s] = 'g';
    chain.push(s);
    while(!chain.empty()) {
        int now = chain.top();
        int hasnext = false;
        for (int i = 0; i < g[now].size(); ++i) {
            if(col[g[now].at(i)] == 'w') {
                chain.push(g[now].at(i));
                col[g[now].at(i)] = 'g';
                hasnext = true;
                break;
            }
        }
        if(!hasnext) {
            col[now] = 'b';
            chain.pop();
            out.push_back(now);
        }

    }

}
int main() {
    cin >> N >> E;
    for (int i = 0; i < E; ++i) {
        int s, t ;
        cin >> s >> t;
        g[s].push_back(t);
//        g[s][t] = 1;
    }

    for (int j = 0; j < N; ++j) {
        col[j] = 'w';
    }
    for (int k = 0; k < N; ++k) {
        int sum = 0;
        sum = g[k].size();
        if(col[k] == 'w') {
            toposort(k);
        }
    }

    for (int l = N-1; l >=0; --l) {
        if(l != N-1) cout << " ";
        cout << out.at(l) ;
    }
    cout <<endl;

    return 0;
}

