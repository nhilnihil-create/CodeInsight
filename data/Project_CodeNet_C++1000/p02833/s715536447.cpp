#include <bits/stdc++.h>
using namespace std;

long long solve(long long N){
    if(N % 2 == 1) return 0;
    
    long long ans = 0;
    N /= 2;
    while(N){
        ans += N/5;
        N /= 5;
    }
    return ans;
}



int main(void){
    long long N; cin >> N;
    cout << solve(N) << endl;
}
