#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int k, a, b;
    cin >> k >> a >> b;

    bool ok = false;
    for(int i=a; i<=b; i++){
        if(i % k == 0) ok = true;
    } 

    if(ok) cout << "OK\n";
    else cout << "NG\n";

    return 0;
}