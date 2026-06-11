#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int h, w;
    cin >> h >> w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }

    long long int ans = 0;
    if(h % 2 != 0 && w % 2 != 0) ans = (h-1) * w / 2 + (w+1)/2;
    else ans = h * w / 2;
    cout << ans << endl;
    return 0;
}