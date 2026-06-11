#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    int cnt = 0, le = (int)s.size();
    rep(i,le/2) {
        if(s[i] != s[le-i-1])
            cnt++;
    }
    
    cout << cnt << endl;
    
    
    
    return 0;
}
