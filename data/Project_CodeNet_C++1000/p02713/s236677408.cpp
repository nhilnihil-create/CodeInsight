#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int t = a % b;
    if(t == 0) return b;
    else return gcd(b, t);
}

int main(){
    int K;
    cin >> K;
    int64_t sum = 0;
    for(int i=1; i<=K; i++){
        for(int j=1; j<=K; j++){
            for(int k=1; k<=K; k++){
                sum += gcd(gcd(i, j), k);
            }
        }
    }
    cout << sum << endl;
}