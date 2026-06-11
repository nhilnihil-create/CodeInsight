#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long cnt = 0;
    vector<long long> rgb_cnt(3);
    string S;

    cin >> N;
    cin >> S;

    for(int i = 0; i < N; i++){
        switch (S[i]) {
        case 'R':
            rgb_cnt[0] += 1;
            break;
        case 'G':
            rgb_cnt[1] += 1;
            break;
        case 'B':
            rgb_cnt[2] += 1;
            break;
        default:
            break;
        }
    }

    cnt = rgb_cnt[0] * rgb_cnt[1] * rgb_cnt[2];

    for(int i = 0; i < N; i++){
        for(int j = 1; j <= (N - i - 1) / 2; j++){
            if(S[i] != S[i+j] && S[i+j] != S[i+2*j] && S[i+2*j] != S[i]){
                cnt--;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}