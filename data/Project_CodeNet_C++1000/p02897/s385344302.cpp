#include <bits/stdc++.h>
using namespace std;


void solve(long long N){
    if (N % 2 == 0) {
        cout << (float(N)/2)/float(N) << endl;
    } else {
        cout << (float(N+1)/2)/float(N) << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
