#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    
    for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        c[i]= b;
        
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    int ans = 1e9 + 7;
    
    for (int tmp = 0; tmp < (1<<n); tmp++){
        
        bitset<13> s(tmp);
        int money = 0;
        vector<int> algo(m);
        
        for (int i = 0; i < n; i++){
            if (s.test(i)){
                money += c[i];
                for (int j = 0; j < m; j++) algo[j] += a[i][j]; 
            }
        }
        
        bool check = true;
        for (int i = 0; i < m; i++){
            if (algo[i]< x) check = false;
        }
        
        if (check) ans = min (ans,money);
    }
    if (ans == 1e9+7) cout << -1 << endl;
    else cout << ans << endl;
}
