#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    cin >> n >> q;
    vector<vector<int>> x(n);
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        x[a-1].push_back(b);
        x[b-1].push_back(a);
    }

    vector<int> order;
    vector<bool> h(n,false);
    queue<int> y;
    h[0]=true;
    order.push_back(1);
    y.push(1);
    vector<int> parent(n);

    while(!y.empty()){
        int v=y.front();
        y.pop();

        for(int nv : x[v-1]){
            if(h[nv-1] == true) continue;

            h[nv-1]=true;
            parent[nv-1]=v;
            y.push(nv);
            order.push_back(nv);
        }
    }

    vector<int> p(n);
    for(int i = 0; i < q; i++) {
        int s,t;
        cin >> s >> t;
        p[s-1] += t;
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int l=order[i];
        if(l==1){
            ans[0]=p[0];
        }
        else{
            ans[l-1] = p[l-1]+ans[parent[l-1]-1];
        }
    }

    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[n-1] << endl;

    return 0;
}