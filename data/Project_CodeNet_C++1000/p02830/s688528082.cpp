#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    rep(i,n) {
        cout << s[i] << t[i];
    }
    cout << endl;
    
    
    return 0;
}
