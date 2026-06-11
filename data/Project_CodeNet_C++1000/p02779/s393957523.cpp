#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    
    set<int> s;
    rep(i,n) {
        int a;
        cin >> a;
        s.insert(a);
    }
    
    if(s.size() == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    
    return 0;
}
