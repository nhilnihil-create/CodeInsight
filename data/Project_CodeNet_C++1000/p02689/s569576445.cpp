#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<int> high(n);
    vector<int> view(n,0);
    vector<vector<int>> road(m,vector<int>(2));
    for (int i = 0; i < n; i++) cin >> high.at(i);
    for (int j = 0; j < m; j++){
        cin >> a >> b;
        a--;
        b--;
        if(high.at(a) <= high.at(b)) view.at(a)++;
        if(high.at(b) <= high.at(a)) view.at(b)++;
    }

    for(int i = 0; i < n; i++){
        if (view.at(i) == 0) ans++;
    }

    cout << ans << endl;
}