#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int max = 0;

    for(int i = 0; i < K; i++){
        if(A > 0){
            max++;
            A--;
        }
        else if(B > 0){
            B--;
        }
        else{
            max--;
            C--;
        }
    }

    cout << max << endl;
}