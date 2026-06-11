#include <bits/stdc++.h>
using namespace std;


void solve(long long H, long long A){
    int cnt = 0;
    while(H > 0){
        H = H - A;
        cnt += 1;
    }
    cout << cnt << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long A;
    scanf("%lld",&A);
    solve(H, A);
    return 0;
}
