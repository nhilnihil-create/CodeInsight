// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
using namespace std;


vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}


int main()
{
    int n, m, k, a,x,y;
    int syogen[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            syogen[i][j] = -1;
        }
    }
    

    cin >> n ;

    for (int i = 0; i < n; i++) {
        cin >> a;

        for (int j = 0; j < a; j++) {
            cin >> x >> y;
            syogen[i][x - 1] = y;
        }
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool ok = true;
        vector<int> S = IntegerToVector(bit, n);
        int state[15];
        for (int i = 0; i < 15; i++) {
            state[i] = 0;
        }
        for (int j : S) {
            state[j] = 1;
        }

        for(int k : S) {
            for (int i = 0; i < n; i++) {
                if (syogen[k][i] == 0) {
                    if (state[i] != 0) {
                        ok = false;
                        break;
                    }
                }
                else if (syogen[k][i] == 1) {
                    if (state[i] != 1) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok == false)break;
        }
        if (ok) {
           if(ans<S.size()) ans = S.size();
        }


    }
    cout << ans << endl;
}

