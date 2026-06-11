#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    string s;
    cin >> n >> s;
    
    bool tf = true;
    if(n % 2 == 1)
        tf = false;
    else {
        rep(i,n/2) {
            if(s[i] != s[n/2 + i]) {
                tf = false;
                break;
            }
        }
    }
    
    if(tf)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    
    return 0;
}
