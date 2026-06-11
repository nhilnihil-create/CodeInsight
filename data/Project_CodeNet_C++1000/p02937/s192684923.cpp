#include <bits/stdc++.h>
using namespace std;

int main() {
    string S,T;
    cin >> S >> T;
    
    int64_t s,t;
    s = S.size();
    t = T.size();
    
    S = S + S;
    
    vector<vector<int64_t>> a(2*s+10,vector<int64_t>(26,2*s));
    for ( int64_t i = 2*s-1; i >= 0; --i){
        for ( int64_t j = 0; j < 26; ++j){
            a[i][j] = a[i+1][j];
        }
        a[i][S[i]-'a'] = i+1;
    }
    
    int64_t cur = 0;
    bool flg = false;
    for ( auto b: T ){
        int64_t c = b - 'a';
        int64_t pos = cur % s;
        if ( a[pos][c] == 2 * s ){
            flg = true;
            break;
        }
        cur = cur + a[pos][c] - pos;
    }
    
    if ( flg ){
        cout << -1 << endl;
    } else {
        cout << cur << endl;
    }
    
    
    return 0;
}
