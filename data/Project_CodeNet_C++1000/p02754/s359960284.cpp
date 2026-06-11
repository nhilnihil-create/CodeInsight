#include <bits/stdc++.h>
using namespace std;


int main(){
    unsigned long long N, A, B;
    cin >> N >> A >> B;

    unsigned long long q = N / (A + B);
    unsigned long long r = N % (A + B);
    
    unsigned long long ans = q*A + min({r, A});

    cout << ans << endl;
    return 0;
}