#include<bits/stdc++.h>
using namespace std;
const int large = 100000;
int main(){
    string S, T;
    int temp = 0, t = large;
    cin >> S >> T;
    for(int i = 0; i < S.size() - T.size() + 1; i++){
        temp = 0;
        for(int j = 0; j < T.size(); j++){
            if(S.at(j + i) != T.at(j)){
                temp++;
            }
        }
        t = min(temp, t);
    }
    cout << t << endl;
    return 0;
}