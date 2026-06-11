#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> cash(n);
    vector<vector<int>> book(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        cin >> cash[i];
        for(int j = 0; j < m; j++){
            cin >> book[i][j];
        }
    }
    int ans = pow(10, 9);
    for(int i = 0; i < pow(2, n); i++){
        int kane = 0, shift = 0;
        vector<int> check(m, 0);
        while(shift < n){
            if(i & (1 << shift)){
                kane += cash[shift];
                for(int j = 0; j < m; j++){
                    check[j] += book[shift][j];
                }
            }
            shift++;
        }
        sort(check.begin(), check.end());
        if(check[0] >= x) ans = min(kane, ans);
    }
    if(ans < pow(10, 9)) cout << ans << endl;
    else cout << -1 << endl; 
}