#include <bits/stdc++.h>
using namespace std;
int father(vector<int>& f, int x){
    return (f[x] == x) ? x : (f[x] = father(f, f[x]));
}
int merge(vector<int>& f, int x, int y){
    x = father(f, x);
    y = father(f, y);
    if (x == y)
        return 0;
    f[x] = y;
    return 1;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int ans = n - 1;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if (merge(f, x, y))
            ans --;
    }
    cout << ans << endl;
}