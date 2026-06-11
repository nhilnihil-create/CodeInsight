#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    double d, t, s;
    cin >> d >> t >> s;
    if(d/s <= t) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}