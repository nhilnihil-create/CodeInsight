#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin >> l >> r;
    int d = min(2019,(r-l));
    int ans = 2019;

    for (int i = 0; i < d; i++){
        for (int j = i+1; j <= d; j++){
            int x = (l+i)%2019;
            int y = (l+j)%2019;
            ans = min(ans, (x*y)%2019);
        }
    }
    cout << ans << endl;

}