#include <bits/stdc++.h>
using namespace std;

bool check(int skill[20], int m, int x){
    for(int i = 0; i < m; i++){
        if(skill[i] < x){
            return false;
        }
    }
    return true;
}


int main(void){
    int n, m, x, ans;
    vector<int> ok;
    cin >> n >> m >> x;
    int c[20], a[20][20];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }


    int price, skill[m];
    price = 0;
    for(int i = 0; i < m; i++) skill[i] = 0;
    for(int i = 0; i < 1<<n; i++){
        for(int j = 0; j < n; j++){
            if((i>>j)%2 == 1){
                price += c[j];
                for(int k = 0; k < m; k++) skill[k] += a[j][k];
            }
        }
        if(check(skill, m, x)){
            ok.push_back(price);
        }
        price = 0;
        for(int j = 0; j < m; j++) skill[j] = 0;
    }
    sort(ok.begin(), ok.end());
    if(ok.empty()) cout << -1 << endl;
    else cout << ok[0] << endl;
            
    return 0;
}
