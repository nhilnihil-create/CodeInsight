#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[])
{
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, A[15], x[15][15], y[15][15];
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    
    int max_honest = 0;
    
    for (int i = 0; i < (1 << N); i++) {
        bitset<15> honest(i);
        int statement = i;
        bool valid = true;
        
        for (int j = 0; j < N; j++) {
            if (!honest.test(j)) {
                continue;
            }
            for (int k = 0; k < A[j]; k++) {
                if (y[j][k]) {
                    int flag = (statement & (0x1 << x[j][k])) >> x[j][k];
                    if (flag == 0) {
                        valid = false;
                        break;
                    }
                } else {
                    int flag = (statement & (0x1 << x[j][k])) >> x[j][k];
                    if (flag == 1) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                break;
            }
        }
        if (!valid) {
            continue;
        }
        if (statement == i) {
            max_honest = max(max_honest,(int) honest.count());
        }
    }
    
    cout << max_honest << endl;
    
    return 0;
}
