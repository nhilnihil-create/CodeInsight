/**
*    author:  Taichicchi
*    created: 09.09.2020 20:16:19
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll X, Y;
    cin >>X >> Y;

    string ans = "No";

    if(Y % 2 == 0){
        for(int i = 0; i <= X ; ++i) {
            if(i * 4 + (X - i) * 2 == Y){
                ans = "Yes";
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}