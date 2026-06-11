#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N, K;
    cin >> N >> K;

    if (K == 1){
        cout << 0 << endl;
    }
    else if(K == N){
        cout << 0 << endl;
    }
    else {
        cout << N - K << endl;
    }
}