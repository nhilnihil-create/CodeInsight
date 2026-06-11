#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s = " ";
    string t;
    cin >> t;
    s += t;
    int N = (int)t.size();
    bool is = true;
    int a = N/2;
    rep(i, a){
        if(s[1+i] != s[N-i]) is = false;
    }
    int b = a/2;
    rep(i, b){
        if(s[1+i] != s[(N-1)/2-i]) is = false;
    }
    rep(i, b){
        if(s[(N+3)/2+i] != s[N-i]) is = false;
    }
    if(is) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}