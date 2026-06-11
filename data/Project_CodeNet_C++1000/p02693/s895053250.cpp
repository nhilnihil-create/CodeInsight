#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int k, a, b;
    cin >> k >> a >> b;
    bool can = false;
    for(int i=a ; i <= b; i++){
        if(i % k == 0) can = true;
    }
    if(can) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}