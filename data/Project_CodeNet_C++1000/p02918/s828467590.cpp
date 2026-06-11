#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    
    int cnt = 0;
    for ( int i = 0; i < N-1; ++i){
        if ( S.at(i) != S.at(i+1) ){
            ++ cnt;
        }
    }
    cnt = max( cnt - 2 * K, 0 );
    
    int ans;
    ans = N - cnt  -  1;
    
    cout << ans << endl;
    
    return 0;
}
