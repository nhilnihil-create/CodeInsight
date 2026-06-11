#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t ans = 0;
    int a, n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                a = min(i, j);
                a = min(a, k);
                for(int l = a; 0 < l; l--){
                    if(i % l == 0 && j % l == 0){
                        if(k % l == 0){
                            ans += l;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

}