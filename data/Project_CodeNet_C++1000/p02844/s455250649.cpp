#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
    cin >> N >> S;
    string number;
    int ans = 0;
    for (int i = 0; i < 1000; i++){
        number = to_string(i);
        if (number.size() == 1){
            number = "00" + number;
        }
        else if (number.size() == 2){
            number = "0" + number;
        }
        int idx = 0;
        for (int j = 0; j < S.size(); j++){
            if (S[j] == number[idx]){
                idx += 1;
            }
            if (idx == 3){
                ans += 1;
                break;
            }
            
        }
    }
    cout << ans << endl;
}