
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    if(k >= a+b){
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    else if(k>=a && k-a<b){
        cout << 0 << ' ' << b-k+a << endl;
        return 0;
    }
    else{
        cout << a-k << ' ' << b << endl;
        return 0;
    }
}