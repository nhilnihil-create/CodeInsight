#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    long long target;
    cin >> target;

    int ans = 0;
    long long money = 100;
    while(true){
        money += money/100;
        ans++;
        if(money >= target) break;
    }
    cout << ans << endl;

    return 0;
}