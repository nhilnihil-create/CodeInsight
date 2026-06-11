#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<vector<int>> test;

void DFS(vector<int> &t){
    int size = t.size();
    if(size == n) test.push_back(t);
    else{
        for(int i=t[size-1]; i<=m; i++){
            vector<int> u = t;
            u.push_back(i);
            DFS(u);
        }
    }
    return ;
}

int main(){
    cin >> n >> m >> q;

    vector<int> a(q), b(q), c(q), d(q);
    for(int i=0; i<q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i] -= 1;
        b[i] -= 1;
    }

    for(int i=1; i<=m; i++){
        vector<int> init = {i};
        DFS(init);
    }

    int ans = 0;
    for(auto t : test){
        //for(int i=0; i<n; i++) cout << t[i] << " ";
        //cout << endl;

        int score = 0;
        for(int i=0; i<q; i++){
            if(t[b[i]] - t[a[i]] == c[i]) score += d[i];
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}