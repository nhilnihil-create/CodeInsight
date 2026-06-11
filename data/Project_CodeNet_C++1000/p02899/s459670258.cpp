#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,0,n) cin >> a.at(i);
    rep(i,0,n) a.at(i)--;
    rep(k,0,n){
        b.at(a.at(k)) = k;
    }
    rep(i,0,n) cout << b.at(i)+1 << " ";
}

//  a 1 2 0
//  b 2 0 1