#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    long long cnt = 0;

    if  (10%P == 0) {
        for (int i=0;i<N; i++) {
            if((S[i]-'0')%P == 0) cnt += i+1;
        }
        cout << cnt << endl;
        return 0;
    }

    int order = 1;
    vector <int> R(N+1);
    int r=0;
    vector <int> v_cnt(P,0);
    v_cnt[0] = 1;
    for (int i=N-1;i>=0;i--){
        r = ((S[i]-'0') * order + r)%P;
        cnt += v_cnt[r];
        v_cnt[r] ++;
        order = (10*order)%P;
    }
    
    cout << cnt << endl;
    return 0;
}