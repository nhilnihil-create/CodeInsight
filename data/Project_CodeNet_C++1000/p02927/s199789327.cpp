#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, d;
    cin >> m >> d;

    int ans = 0;
    for(int i=0; i<=d; i++){
        int d1 = i % 10;
        int d2 = i / 10;
        if(d1 >= 2 && d2 >= 2 && d1 * d2 <= m){
            //cout << d1 << " " << d2 << endl;
            ans += 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}