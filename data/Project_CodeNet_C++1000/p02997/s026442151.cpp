#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,K;
    cin >> N >> K;
    
    int X = (N-1)*(N-2)/2 - K;
    
    if ( X < 0 ){
        cout << -1 << endl;
    } else {
        cout << N - 1 + X << endl;
        for ( int i = 0; i < N-1; ++i){
            cout << 1 << " " << i+2 << endl;
        }
        int count = 0;
        bool flg = false;
        if ( X != 0 ){
            for ( int i = 2; i < N; ++i){
                for ( int j = i + 1; j <= N; ++j){
                    cout << i << " " << j << endl;
                    ++count;
                    if ( count == X ) {
                        flg = true;
                        break;
                    }
                }
                if ( flg ) break;
            }
        }
    }
    
    return 0;
}
