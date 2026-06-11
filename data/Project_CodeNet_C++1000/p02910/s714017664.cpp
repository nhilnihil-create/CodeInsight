#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    bool f = true;
    rep(i, 0, n) {
        if(s[i] == 'L' && i%2 == 0) f = false;
        if(s[i] == 'R' && i%2 == 1) f = false;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}