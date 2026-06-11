#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B){
    int cnt = 1;
    for(int i = 0; i < 20; ++i){
        if(i > 0){
            cnt = A * i - (i-1);
        }
        if(cnt >= B){
            cout << i << endl;
            break;
        }
    }
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
