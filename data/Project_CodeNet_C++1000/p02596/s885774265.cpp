#include <bits/stdc++.h>
using namespace std;
int main(){
    int K,i,p = 7;
    bool b = true;
    cin >> K;
    for(i = 0;i < K;i++){
        if(p % K == 0){
            b = false;
            cout << i + 1 << endl;
            break;
        }
        p = (p * 10 + 7) % K;
    }
    if(b){
        cout << -1 << endl;
    }
}