#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    for(int i = 0; i < S.size(); i++){
        int A = (int)S.at(i) + N;
        if(A > 90){
            A -= 26;
        }
        cout << (char)A;
    }
    cout << endl;
}