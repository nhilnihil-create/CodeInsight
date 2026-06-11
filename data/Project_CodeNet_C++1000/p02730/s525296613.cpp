#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, a, b;
    cin >> S;
    int N = S.size();
    for(int i = 0; i < (N - 1) / 2; i++){
        a.push_back(S.at(i));
    }
    for(int i = (N +  3) / 2 - 1; i < N; i++){
        b.push_back(S.at(i));
    }
    if(a == b){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}