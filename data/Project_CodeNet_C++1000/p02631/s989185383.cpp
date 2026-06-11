#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    int hoge = A.at(0);
    for (int i = 1; i < N; i++) {
        hoge ^= A.at(i);
    }
    for (int i = 0; i < N; i++) cout << (hoge ^ A.at(i)) << endl;
}