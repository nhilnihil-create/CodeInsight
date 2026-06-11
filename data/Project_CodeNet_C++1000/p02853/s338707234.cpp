#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    if(x >= 4) x = 0;
    if(y >= 4) y = 0;

    vector<int> prize = {0, 300000, 200000, 100000};
    int ans = prize[x] + prize[y];

    if(x == 1 && y == 1) ans += 400000; 
    cout << ans << endl;
    return 0;
}