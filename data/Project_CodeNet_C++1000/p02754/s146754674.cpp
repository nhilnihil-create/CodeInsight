#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long  N,A,B;
    cin >> N >> A >> B;
    
    long long Q,mod,r;
    Q=N/(A+B);
    mod=N%(A+B);
    
    if (mod>=A) {
        r=A;
    }
    else{
        r=mod;
    }
    
    long long ans=Q*A+r;
    
    cout << ans << endl;
    
}