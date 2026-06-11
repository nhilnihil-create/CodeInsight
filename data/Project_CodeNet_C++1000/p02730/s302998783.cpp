#include<bits/stdc++.h>
using namespace std;

bool kaibun(string S, int A, int B){
    // Sの文字数は3以上の奇数
    // SのA文字目からB文字目までが回文かどうかを判定する関数
    int i = A-1;
    int j = B-1;
    while (i <= j){
        if (S.at(i) != S.at(j))
            return false;
        i += 1;
        j += -1;
    }
    return true;
}

int main(){
    string S;
    cin >> S;
    int N = S.size();
    if (kaibun(S, 1, N) && kaibun(S, 1, (N-1)/2) && kaibun(S, (N+3)/2, N))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}