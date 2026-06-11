#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> s(M,0), c(M,0);

    vector<int> digit(N, -1);

    bool conflict = false;

    for (int i = 0; i < M; i++)
    {
        cin >> s[i] >> c[i];

        if(digit[s[i] - 1] < 0){
            digit[s[i] - 1] = c[i];
        } else if(digit[s[i] - 1] != c[i]){
            conflict = true;
        }
    }

    bool isNdig = true;
    if(digit[0] == 0 && N > 1) {
        isNdig = false;
    } else if(digit[0] < 0){
        if(N > 1){
            digit[0] = 1;
        } else{
            digit[0] = 0;
        }
    }

    if(isNdig & !conflict){
        for(int i = 0; i < N; i++){
            int val = digit[i];
            if(val < 0){
                cout << 0;
            } else {
                cout << val;
            }
        }

    cout << endl;
    } else{
        cout << -1 << endl;
    }

    return 0;
}
