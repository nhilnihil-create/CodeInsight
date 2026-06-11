#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool win = false;
    while(true){
        c -= b;
        if(c <= 0){
            win = true;
            break;
        } 

        a -= d;
        if(a <= 0){
            win = false;
            break;
        }
    }

    if(win) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}