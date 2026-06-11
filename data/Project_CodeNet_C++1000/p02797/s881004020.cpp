#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,k,s,d=1e9;
    cin >> n >> k >> s;
    if(s==d) d = 1;
    rep(i,k) cout << s << ' ';
    rep(i,n-k) cout << d << ' ';
    cout << endl;
}
