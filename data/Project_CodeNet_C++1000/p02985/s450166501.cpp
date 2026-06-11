#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n, k;
    cin >> n >> k;
    vec v[n];
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool visited[n];
    fill(visited, visited + n, false);
    queue<int> que;
    que.push(0);
    visited[0] = true;
    ll ans = k;
    bool init = true;
    while(que.size() > 0){
        int e = que.front();
        que.pop();
        int num;
        if(init){
            num = k - 1;
            init = false;
        }else{
            num = k - 2;
        }
        for (int i = 0; i < v[e].size(); i++){
            if(visited[v[e][i]]) continue;
            visited[v[e][i]] = true;
            ans *= num;
            ans %= mod;
            num--;
            que.push(v[e][i]);
            
        }
    }
    cout << ans << endl;
}