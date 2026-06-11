#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int N,K; cin >> N >> K;
    int R,S,P; cin >> R >> S >> P;
    long long score = 0;
    string T; cin >> T;

    //同じ手あり
    for(int i=0; i<N; i++) {
        if(T[i] == 'r') score += P;
        else if(T[i] == 's') score += R;
        else if(T[i] == 'p') score += S;
    }

    //かぶり削除
    for(int j=0; j<K; j++){
        for(int i=K+j; i<=N; i+=K) {
            if(T[i] == T[i-K]) {
                if(T[i] == 'r') score -= P;
                else if(T[i] == 's') score -= R;
                else if(T[i] == 'p') score -= S;
                i+=K;
            }
        }
    }
cout << score << endl;
}