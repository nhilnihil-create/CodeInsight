#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = 0;
    ll buf = N / (A+B);
    ans += A*buf;
    buf = N % (A+B);
    if(buf >= A) ans += A;
    else ans += buf;
    cout << ans << endl;
    return 0;
}