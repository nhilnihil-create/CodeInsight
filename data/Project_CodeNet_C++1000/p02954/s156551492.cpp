#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    char last;
    int lcnt,rcnt;
    int *pcnt;
    cin >> S;

    int N = S.size();
    vector<int> sq(N,0);
    // RLの並びの偶奇を見る。 LRで分断される
    lcnt = 0; rcnt = 1;
    pcnt = &rcnt;
    last = 'R';
    for(int i=1;i<S.size();i++) {
        if(last != S[i]) {
            if(last == 'L'){
                //計算 今のポジション
                sq[i-lcnt] += rcnt / 2;
                sq[i-lcnt] += (lcnt % 2) ? (lcnt / 2) + 1 : lcnt / 2; 
                sq[i-lcnt-1] += (rcnt % 2) ? (rcnt/2) + 1 : rcnt / 2; 
                sq[i-lcnt-1] += lcnt / 2; 
                lcnt = 0;rcnt = 0;
                pcnt = &rcnt;
            } else {
                pcnt = &lcnt;
            }
        }
        (*pcnt)++;
        last = S[i];
    }

    // 最後にも計算
                sq[N-lcnt] += rcnt / 2;
                sq[N-lcnt] += (lcnt % 2) ? (lcnt / 2) + 1 : lcnt / 2; 
                sq[N-lcnt-1] += (rcnt % 2) ? (rcnt/2) + 1 : rcnt / 2; 
                sq[N-lcnt-1] += lcnt / 2; 
    for(int i=0;i<N;i++) {
        cout << sq[i] << " ";
    }
    cout << endl;

    return 0;
}
