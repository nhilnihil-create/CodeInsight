#include <bits/stdc++.h>

using namespace std;

int main() {
        string T, S;
        cin >> S >> T;
        int ls = S.size();
        int lt = T.size();
        int m = INT_MAX;
        for(int i = 0; i < ls - lt + 1; i++) {
                int res = 0;
                for(int j = 0; j < lt; j++) {
                        if(T[j] != S[i+j]) res ++;
                }
                m = min(m, res);
        }
        cout << m << endl;
}
