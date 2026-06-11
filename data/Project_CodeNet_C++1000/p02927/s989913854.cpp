#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= m; j++){
            if(i % 10 < 2 || i / 10 < 2)
                continue;
            if((i % 10) * (i / 10) == j)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}