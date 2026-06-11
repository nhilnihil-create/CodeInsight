#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int p, q, r;
    cin >> p >> q >> r;
    cout << p + q + r - max({p, q, r});

    return 0;
}