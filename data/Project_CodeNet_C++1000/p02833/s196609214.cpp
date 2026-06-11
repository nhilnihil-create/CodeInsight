#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    ll N;
    cin >> N;
    if(N%2==1)
        cout << 0 << endl;
    else{
        ll p5=10,ans=0;
        while(N/p5){
            ans += N / p5;
            p5 *= 5;
        }
        cout << ans << endl;
    }
}