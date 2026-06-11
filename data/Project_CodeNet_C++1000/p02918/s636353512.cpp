#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < N - 1; i++){
        if(S[i] != S[i + 1]) cnt++;
    }
    if(cnt <= K * 2) cout << N - 1 << endl;
    else{
        cnt -= K * 2;
        cout << N - 1 - cnt << endl;
    }
}