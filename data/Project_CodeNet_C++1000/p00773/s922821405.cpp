#include<bits/stdc++.h>
using namespace std;

int main(){

    while(1){
        int x, y, s; cin >> x >> y >> s;
        if(x == 0) break;
        int ans = 0;
        for(int i = 1; i < 1010; i++){
            for(int j = 1; i + j < 1010; j++){
                if(i*(100 + x) / 100 + j * (100 + x) / 100 == s){
                    ans = max(ans, i*(100 + y) / 100 + j * (100 + y) / 100);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
