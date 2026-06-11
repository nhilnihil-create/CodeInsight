#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt = 0, cnt2 = 0;
    for(int i = 0; i < N - 1; i++){
        if(S[i] == 'L' && S[i + 1] == 'R') cnt2++;
        else if(S[i] == 'R' && S[i + 1] == 'L') cnt++;
    }
    if(cnt2 + cnt <= 2*K){
        cout << N - 1 << endl;
        return 0;
    }
    for(int i = 0; i < K; i++){
        if(cnt == 0 && cnt2 == 0) break;
        if(cnt == 0 && cnt2 != 0) cnt2--;
        else{
            cnt--;
            cnt2--;
        }
    }
    cout << N - 1 - cnt - cnt2 << endl;
}