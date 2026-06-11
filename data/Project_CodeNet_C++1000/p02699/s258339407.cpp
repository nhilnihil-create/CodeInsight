#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int s, w;
    cin >> s >> w;
    if(w >= s) cout << "unsafe\n";
    else cout << "safe\n";

    return 0;
}