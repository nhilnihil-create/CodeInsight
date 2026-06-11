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

const int MAX_V = 100005;
vec v[MAX_V*3];
bool visited[MAX_V*3];


int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b+MAX_V);
        v[a+MAX_V].push_back(b+2*MAX_V);
        v[a+2*MAX_V].push_back(b);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    // cout << 1 << endl;
    queue<P> que;
    que.push(P(s, 0));
    visited[s] = true;
    while(que.size() > 0){
        P p = que.front();
        que.pop();
        int e = p.first;
        int c = p.second;
        if(e == t){
            cout << c / 3 << endl;
            return 0;
        }
        rep(i, v[e].size()){
            if(visited[v[e][i]]) continue;
            visited[v[e][i]] = true;
            que.push(P(v[e][i], c + 1));
        }
        // cout << 1 << endl;
    }
    cout << -1 << endl;
}