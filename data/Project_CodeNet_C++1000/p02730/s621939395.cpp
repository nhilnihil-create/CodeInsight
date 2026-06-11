#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    int count = 0;
    for(int i = 0; i < (N-1)/2; i++){
        if(S.at(i) == S.at((N+3)/2-1+i)){
            count++;
        }
    }
    if(count == (N-1)/2){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}