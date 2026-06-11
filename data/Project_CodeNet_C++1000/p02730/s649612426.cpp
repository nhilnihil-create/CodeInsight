#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

bool kai(string s, int b, int e) {
    int n = e - b;
    bool tf = true;
    for(int i = b; i < n/2; i++) {
        if(s[i] != s[n-1-i])
            tf = false;
    }
    
    return tf;
}

int main() {
    string s;
    cin >> s;
    
    int n = (int)s.size();
    
    bool ans1 = kai(s,0,n);
    bool ans2 = kai(s,0,n/2);
    bool ans3 = kai(s,(n+1)/2,n);
    //cout << ans1 << ans2 << ans3 << endl;
    
    if(ans1 && ans2 && ans3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}


