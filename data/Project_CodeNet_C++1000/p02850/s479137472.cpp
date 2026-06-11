#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    vector<int> g[N];
    map<P ,int> m;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if(a > b) swap(a, b);
        m[P(a, b)] = i;
    }
    
    int num = 0;
    for(int i=0; i<N; i++){
        num = max(num, (int)g[i].size());
    }

    int c[N-1];
    fill(c, c+N-1, -1);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        bool used[num];
        fill(used, used+num, false);
        for(int i=0; i<g[now].size(); i++){
            int a = now;
            int b = g[now][i];
            if(a > b) swap(a, b);
            int en = m[P(a, b)];
            if(c[en] != -1) used[c[en]] = true;
        }
        int color = 0;
        for(int i=0; i<g[now].size(); i++){
            while(used[color]){
                color++;
            }
            int a = now;
            int next = g[now][i];
            int b = next;
            if(a > b) swap(a, b);
            int en = m[P(a, b)];
            if(c[en] == -1){
                c[en] = color;
                used[color] = true;
                q.push(next);
            }
        }
    }

    cout << num << endl;
    for(int i=0; i<N-1; i++){
        cout << c[i]+1 << endl;
    }

    return 0;
}
