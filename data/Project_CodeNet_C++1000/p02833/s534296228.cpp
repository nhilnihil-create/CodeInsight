#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    ll n;cin >> n;
    bool e=false;
    if(n%2==0) e=true;

    if(!e){
        cout << 0 << endl;
        return 0;
    }

    ll a=0;
    n /= 10;
    a += n;
    while(n>=5){
        n /= 5;
        a += n;
        
    }    

    cout << a << endl;

    return 0;
}