#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;cin>>N;
    ll 	ans=0,t=10;
    while(t<=N){
        ans += N/t;
        t *= 5;       
    }
    if(N%2!=0)cout << 0 << endl;
    else cout << ans << endl;
}