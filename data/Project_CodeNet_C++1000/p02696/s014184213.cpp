
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//floor(a/b)=(a-a%b)/bとすることでfloorを消せる

int main(){
    ll a, b, n;
    cin >> a >> b >> n;

    ll x=n;
    if(n>= b-1) x = b-1;
    ll ans = a*(x%b)/b;
    cout << ans << endl;
    

    
}   