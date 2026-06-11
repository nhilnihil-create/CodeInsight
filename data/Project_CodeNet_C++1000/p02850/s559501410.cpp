#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;



int main(){
    int n;
    cin >> n;
    vector<vector<int> > v(n);
    vector<P> dec;
    rep(i, n - 1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(x > y) swap(x, y);
        dec.push_back(P(x, y));
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<bool> visited(n, false);
    queue<P> que;
    que.push(P(0, 0));
    visited[0] = true;
    int k = 0;
    map<P, int> mp;
    while(que.size() > 0){
        P p = que.front();
        que.pop();
        int e = p.first;
        int num = p.second;
        int num_ = 1;
        rep(i, v[e].size()){
            int x = e, y = v[e][i];
            if(visited[y]) continue;
            if(num_ == num) num_++;
            visited[y] = true;
            que.push(P(y, num_));
            if(x > y) swap(x, y);
            mp.insert(make_pair(P(x, y), num_));
            k = max(k, num_);
            num_++;
        }
    }
    cout << k << endl;
    rep(i, n - 1){
        cout << mp.at(dec[i]) << endl;
    }
}