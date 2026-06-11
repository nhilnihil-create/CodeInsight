#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct union_find{
    vector<int> r;
    
    union_find(int n){
        r = vector<int> (n, -1);
    }
    
    int root(int x){
        if(r[x] < 0){
            return x;
        }else{
            return r[x] = root(r[x]);
        }
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }
        if (r[rx] > r[ry]) {
            swap(rx, ry);
        }
        r[rx] += r[ry];
        r[ry] = rx;
    }
    
    int size(int x){
        return -r[root(x)];
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;
    union_find UF(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        UF.unite(a - 1, b - 1);
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i ++){
        ans = max(ans, UF.size(i));
    }
    cout << ans << endl;
    return 0;
}