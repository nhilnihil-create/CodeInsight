#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> T;
    for (int i = 0; i < N; ++i) {
        T.push_back(S[i] - '0');
    }

    int cnt = 0;
    
    for(int n = 0; n < 1000; ++n) {
        int t = n / 100;
        int m = (n - (100 * t)) / 10;
        int b = n - (100*t) - (10*m);
        bool ok1 = false;
        bool ok2 = false;
        bool ok3 = false;
        int i1 = 0;
        int i2 = 0;
        for(int i = 0; i < N; ++i) {
            if(T[i] == t) {
                ok1 = true;
                i1 = i;
                break;
            }
        }
        if(ok1) {
            for(int i = i1+1; i < N; ++i) {
                if(T[i] == m) {
                    ok2 = true;
                    i2 = i;
                    break;
                }
            }
        }
        if(ok2) {
            for(int i = i2+1; i < N; ++i) {
                if(T[i] == b) {
                    ok3 = true;
                    break;
                }
            }
        }
        if(ok1 && ok2 && ok3) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}