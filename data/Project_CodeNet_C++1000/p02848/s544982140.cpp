#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    string s;
    cin >> n >> s;
    
    rep(i,s.size()) {
        s[i] += n;
        if(s[i] > 'Z') {
            s[i] -= 26;
        }
    }
    
    cout << s << endl;
    
    
    return 0;
}
