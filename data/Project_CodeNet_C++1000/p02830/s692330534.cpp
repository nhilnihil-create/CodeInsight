#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<char> vec_S(N);
    vector<char> vec_T(N);
    for (int i=0; i<N; i++) {
        vec_S.at(i) = S.at(i);
        vec_T.at(i) = T.at(i);
    }
    vector<char> vec(2*N);
    for (int i=0; i<2*N; i++) {
        if (i%2 == 0) {
            vec.at(i) = vec_S.at(i/2);
        }
        else {
            vec.at(i) = vec_T.at(i/2);
        }
    }
    string answer = "aa";
    for (int i=1; i<N; i++) {
        answer+="aa";
    }
    for (int i=0; i<2*N; i++) {
        answer.at(i) = vec.at(i);
    }
    cout << answer << endl;
}