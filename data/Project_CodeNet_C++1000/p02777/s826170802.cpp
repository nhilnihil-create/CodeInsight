#include <bits/stdc++.h>
using namespace std;


void solve(std::string S, std::string T, long long A, long long B, std::string U){
    if(S == U) A -= 1;
    else B -= 1;
    cout << A << " " << B << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    std::string U;
    std::cin >> U;
    solve(S, T, A, B, U);
    return 0;
}
