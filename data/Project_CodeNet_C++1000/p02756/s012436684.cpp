#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    string s;
    deque<char> deq;
    cin >> s;
    rep(i,s.size()) {
        deq.push_back(s[i]);
    }
    int q;
    cin >> q;
    bool rev = false;
    rep(i,q) {
        int t,f;
        char c;
        cin >> t;
        if(t == 1) {
            rev = !rev;
        } else {
            cin >> f >> c;
            if((f == 1 && rev == false) || f == 2 && rev == true) {
                deq.push_front(c);
            } else {
                deq.push_back(c);
            }
        }
    }
    if(rev) reverse(deq.begin(), deq.end());
    for(auto c: deq) {
        cout << c ;
    }
    cout << endl;
}