#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    if(S.size() <= N){
        cout << S << endl;
        return 0;
    } else if(N < S.size()) {
        S.erase(N);
        cout << S << "..." << endl;
        return 0;
    }
}