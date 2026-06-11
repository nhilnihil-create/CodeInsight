#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main(){
    int K;
    int res = 0;

    cin >> K;

    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= K; j++){
            for(int k = 1; k <= K; k++){
                res += gcd(i,gcd(j,k));
            }
        }
    }

    cout << res << endl;

    return 0;
}