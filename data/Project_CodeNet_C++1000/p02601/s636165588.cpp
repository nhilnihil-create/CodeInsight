#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int times = 0;
    while(b <= a){ b *= 2; times += 1; }
    while(c <= b){ c *= 2; times += 1; }

    if(times <= k) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}