#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll a,b,c,k; cin >> a >> b >> c >> k;
    ll sum = 0;
    ll x = k - a; //bの数
    ll y = x - b; //cの数
    if(x<=0) {
        sum += k;
        cout << sum << endl; 
        return 0;
    }
    else {
        sum += a;
        if(y<=0) {
            cout << sum << endl;
            return 0;
        }
        else {
            sum -= y;
            cout << sum << endl;
            return 0;
        }
    }
}