#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000

using namespace std;

vector<int> dist(const int& n, const int& x, const int& y){
    vector<int> d(n, inf);
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur > 0 && d[cur-1] == inf){
            q.push(cur-1);
            d[cur-1] = d[cur]+1;
        }
        if (cur < n-1 && d[cur+1] == inf){
            q.push(cur+1);
            d[cur+1] = d[cur]+1;
        }
        if (cur == x && d[y] == inf){
            q.push(y);
            d[y] = d[cur]+1;
        }
        if (cur == y && d[x] == inf){
            q.push(x);
            d[x] = d[cur]+1;
        }
    }
    return d;
}

signed main(){
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<int> res(n, 0);
    vector<int> xdist = dist(n, x, y);
    vector<int> ydist = dist(n, y, x);
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int dst = inf;
            dst = min(dst, j-i);
            dst = min(dst, xdist[j]+ydist[i]+1);
            dst = min(dst, xdist[i]+ydist[j]+1);
            res[dst]++;
        }
    }
    for (int i = 1; i < n; i++){
        cout << res[i] << endl;
    }
    return 0;
}





















