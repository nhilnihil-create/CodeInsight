#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    int cnt = 0;
    for(int m = 4; m <= n; m++){
        for(int j = 10; j <= d; j++){
            if(m == (j/10)*(j%10) && (j/10) >= 2 && (j%10) >= 2){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}