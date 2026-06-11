#include <bits/stdc++.h>
using namespace std;

int main(){
    string M,D;
    cin >> M >> D;
    int ans = 0;

    if(D.size() == 1){
        cout << ans << endl;
        return 0;
    }
    int m = stoi(M);
    int d = stoi(D);
    for(int i = 12; i <= d; i++){
        for(int j = 1; j <= m; j++){
            int d1 = i % 10;
            int d2 = (i/10) % 10;
            if(d1 >= 2 && d2 >= 2 && d1 * d2 == j){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
