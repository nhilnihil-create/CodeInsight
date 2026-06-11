#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, T t){return v2<T>(r, vector<T>(c, t));}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++){
        queue<int> q;
        vector<bool> v(n, false);
        vector<int> d(n, 1e9);
        q.push(i);
        v[i] = true;
        d[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vector<int> adj;
            if(node > 0) adj.push_back(node-1);
            if(node < n-1) adj.push_back(node+1);
            if(node == x) adj.push_back(y);
            if(node == y) adj.push_back(x);

            for(int next : adj){
                if(!v[next]){
                    v[next] = true;
                    d[next] = 1+d[node];
                    q.push(next);
                } 
            }
        }

        for(int j = 0; j < n; j++){
            ans[d[j]]++;
        }
    }

    for(int i = 1; i < n; i++){
        cout << ans[i]/2 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
