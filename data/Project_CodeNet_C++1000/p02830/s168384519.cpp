#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S,T;
    char temp;
    cin >> N;
    cin >> S >> T;

    for (int i =0; i < N; i++){
        cout << S.at(i) << T.at(i);
    }

    cout << endl;
}