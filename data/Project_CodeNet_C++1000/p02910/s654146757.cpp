#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    rep(i,s.size()) {
        if((i % 2 == 0 && s[i] == 'L') ||
           (i % 2 == 1 && s[i] == 'R')) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    
    
    return 0;
}
