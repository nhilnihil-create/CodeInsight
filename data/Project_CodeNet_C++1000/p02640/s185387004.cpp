#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int x, y; cin >> x >> y;

    int k, flag=0;
    for(int i=0; i<=x; i++){
        k = x - i;
        if(y == i*2+k*4) flag=1;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}