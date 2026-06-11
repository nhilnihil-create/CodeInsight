#include <iostream>
#include <vector>
using namespace std;

void calc(vector<vector<int>> &T, vector<int> &ans, vector<bool> &isvisit, int parent, int cur){
    if(isvisit[cur]) return;
    else isvisit[cur] = true;
    ans[cur] += ans[parent];
    for(int i = 0; i < T[cur].size(); i++){
        calc(T, ans, isvisit, cur, T[cur][i]);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> T(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    vector<int> ans(n+1, 0);
    vector<bool> isvisit(n+1, false);
    for(int i = 0; i < q; i++){
        int p, x;
        cin >> p >> x;
        ans[p] += x;
    }

    calc(T, ans, isvisit, 0, 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}