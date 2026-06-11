#include <iostream>
#include <string>
using namespace std;


int main(){
    string S, T;
    cin >> S;
    cin >> T;
    int S_l = S.length(), T_l = T.length();

    int roop = S_l - T_l + 1;
    int ans = T_l;

    for (int i = 0; i < roop; ++i){
        int count = 0;
        for (int j = 0; j < T_l; ++j){
            if (S[i + j] == T[j]){
                //書き換える必要なし
            } else{
                count += 1;
            }
        }
        ans = (ans > count ? count : ans);
    }

    cout << ans << endl;
}