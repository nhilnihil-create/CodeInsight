#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,M;
    cin >> N >> K;

    int kmax = (N-1)*(N-2)/2;

    if( kmax < K ){
        cout << -1 << endl;
        return 0;
    }

    M = (N-1) + ( kmax - K );

    cout << M << endl;

    for(int i=2; i<=N; i++){
            cout << 1 << " " << i << endl;
    }

    int count = 0;

    for(int i=2; i<N; i++){
        for(int j=i+1; j<=N; j++){
            if( count >= kmax - K ) break;
            cout << i << " " << j << endl;
            count++;
        }
        if( count >= kmax - K ) break;
    }

   return 0; 
}