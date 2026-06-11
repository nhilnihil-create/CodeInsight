#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n;
    cin >> n;
    int x=0;
    rep(i,n){
        int a;
        cin >> a;
        x ^= a;
    }
    if(!x)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}