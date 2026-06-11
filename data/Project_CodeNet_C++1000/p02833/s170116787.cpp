#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const ll mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
    if(n%2 == 0){
        ll t = 0;
        ll f = 0;
        ll i=1;
        ll j=1;
        while(n/pow(2,i)){
            t += i*(n/pow(2,i));
            i++;
        }
        ll x = 2;
        while(n>=(pow(5,j)*2)){
            j++;
            x*=5;
            f += n/x;
        }
        cout << f << endl;
        return 0;

    }
    else{
        cout << 0 << endl;
        return 0;
    }
}