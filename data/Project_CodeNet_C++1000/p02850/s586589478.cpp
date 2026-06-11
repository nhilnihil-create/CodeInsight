#include <bits/stdc++.h>

using namespace std;


using i64 = long long;

signed main(){
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> a[i] >> b[i];
    for(int i = 0; i < n - 1; ++i)
        --a[i], --b[i];
    vector<vector<int>> edges(n);
    for(int i = 0; i < n - 1; ++i){
        edges[a[i]].emplace_back(i);
        edges[b[i]].emplace_back(i);
    }
    vector<int> v(n - 1, -1);
    function<void(int,int)> f = [&](int x, int col){
        int k = (col == 0);
        for(auto idx : edges[x]){
            if(v[idx] != -1)
                continue;
            v[idx] = k;
            f(a[idx] == x ? b[idx] : a[idx], k);
            k = (k + 1 == col ? k + 2 : k + 1);
        }
    };
    f(0, -1);
    cout << *max_element(v.begin(), v.end())+1 << endl;
    for(int i = 0; i < n - 1; ++i)
        cout << v[i] + 1 << endl;
}
