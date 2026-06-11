#include <bits/stdc++.h>
using namespace std;
 

int main() {
    int N,K,R,S,P;
    cin >> N >> K >> R >> S >> P;

    string T;
    cin >> T;

    int Ans = 0;
    int chk = 0;

    for(int i = 0; i < K; i++){
        chk = 0;

        for(int j = i; j < N; j += K){
            if(j >= K && T.at(j - K) == T.at(j) && chk%2 == 0){
                chk++;
                continue;
            }else if(j >= K && T.at(j - K) == T.at(j) && chk%2 != 0){
                chk++;
                if(T.at(j) == 'r') Ans += P;
                if(T.at(j) == 'p') Ans += S;
                if(T.at(j) == 's') Ans += R;
            }else{
                chk = 0;
                if(T.at(j) == 'r') Ans += P;
                if(T.at(j) == 'p') Ans += S;
                if(T.at(j) == 's') Ans += R;

            }
        }
    }

    cout << Ans << endl;



}
