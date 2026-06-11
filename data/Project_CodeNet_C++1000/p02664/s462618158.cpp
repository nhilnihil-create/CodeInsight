#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    string t; cin >> t;
    rep(i, t.size()){
        if (t[i] == '?') cout << 'D';
        else cout << t[i];
    }
    cout << "\n";
}