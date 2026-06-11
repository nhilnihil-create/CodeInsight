#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >>N;
    long double ans =0;
    for(int i=0;i<N;i++){
        long double a;
        cin >> a;
        ans += (1/a);
    }
    cout <<  setprecision(10)<<1/ans <<endl;
    return 0;
}