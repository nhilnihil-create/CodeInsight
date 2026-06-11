#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {
    string s; cin >> s;
    ll q; cin >> q;
    int cmd;
    char c;
    int f;
    bool flip = false;

    for(int i = 0; i < q; i++){
        cin >> cmd;
        if(cmd == 1) flip = !flip;
        else{
            cin >> f >> c;
            if(flip) f = (f == 1)?2:1;
            if(f == 2) s += c;
            else s = c+s;
        }
    }

    if(flip) reverse(s.begin(),s.end());
    cout << s;

    return 0;
}
