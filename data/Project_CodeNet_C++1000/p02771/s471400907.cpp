#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long A, long long B, long long C){
    if(A == B && A == C) cout << NO << endl;
    else if(A != B && A != C && B != C) cout << NO << endl;
    else cout << YES << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}
