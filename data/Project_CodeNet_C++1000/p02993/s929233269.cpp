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
    
    rep(i,3) {
        if(s[i] == s[i+1]) {
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
    
    
    
    return 0;
}
