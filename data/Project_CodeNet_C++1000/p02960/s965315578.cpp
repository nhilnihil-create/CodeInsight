#include <bits/stdc++.h>

#define llint long long int
#define P (1000000000 + 7)

using namespace std;

int main(){
    string S;

    cin >> S;

    vector<vector<llint>> count(S.length(), vector<llint>(13, 0));

    if(S[S.length() - 1] == '?'){
        for(int i = 0; i < 10; i ++){
            count[S.length() - 1][i] = 1;
        }
    }else{
        count[S.length() - 1][S[S.length() - 1] - '0'] = 1;
    }
    vector<int> pow10(S.length());

    pow10[S.length() - 1] = 1;

    for(int i = S.length() - 2; i >= 0; i --){
        pow10[i] = (pow10[i + 1] * 10) % 13;
    }
    for(int i = S.length() - 2; i >= 0; i --){
        if(S[i] == '?'){
            for(int j = 0; j < 10; j ++){
                int d = (j * pow10[i]) % 13;

                for(int k = 0; k < 13; k ++){
                    count[i][(k + d) % 13] += count[i + 1][k];
                    count[i][(k + d) % 13] %= P;
                }
            }
        }else{
            int d = ((S[i] - '0') * pow10[i]) % 13;

            for(int j = 0; j < 13; j ++){
                count[i][(j + d) % 13] += count[i + 1][j];
                count[i][(j + d) % 13] %= P;
            }
        }
    }
    cout << count[0][5] << endl;
}