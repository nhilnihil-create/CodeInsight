#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B){
    for(long long i = 1; i <=3; ++i){
        if(i != A && i != B) cout << i << endl;
    }
    return;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
