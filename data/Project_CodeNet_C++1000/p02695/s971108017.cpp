#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size()-1; i++){
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << "]" << endl;
}

int main(void){
    int n, m, q, ans = 0;
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    queue<vector<int>> que;
    for(int i = 1; i <= m; i++){
        vector<int> temp(1,i);
        que.push(temp);
    }
    while(!que.empty()){
        vector<int> top = que.front();
        if(top.size() == n){
            // calc point of top
            int point = 0;
            for(int i = 0; i < q; i++){
                if(top[b[i]-1]-top[a[i]-1] == c[i]){
                    point += d[i];
                }
            }
            ans = max(ans, point);
            que.pop();
        } else {
            for(int i = top.back(); i <= m; i++){
                // add
                vector<int> temp = top;
                temp.push_back(i);
                que.push(temp);
            }
            que.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
