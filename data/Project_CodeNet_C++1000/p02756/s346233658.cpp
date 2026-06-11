#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    string s;
    int q;
    cin >> s >> q;
    
    deque<char> d;
    rep(i,s.size()) {
        d.push_back(s[i]);
    }
    
    bool to = true;
    
    rep(i,q) {
        int t;
        cin >> t;
        if(t == 1) {
            to = !to;
        }
        else {
            int f;
            char c;
            cin >> f >> c;
            
            if(f == 1) {
                if(to)
                    d.push_front(c);
                else
                    d.push_back(c);
            }
            else {
                if(to)
                    d.push_back(c);
                else
                    d.push_front(c);
            }
        }
    }
    
    if(to) {
        for(int i = 0; i < d.size(); i++) {
            cout << d[i];
        }
    }
    else {
        for(int i = (int)d.size() - 1; i >= 0; i--) {
            cout << d[i];
        }
    }
    
    cout << endl;
    
    
    return 0;
}


