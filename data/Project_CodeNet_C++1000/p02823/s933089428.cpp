#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    ll n;cin >> n;
    ll a,b;cin >> a >> b;
    if(a%2 == b%2){
        cout << (b-a)/2 << endl;
        return 0;
    }

    else{
        cout << (b-a-1)/2 + min(a-1,n-b)+1 << endl;
    }

    return 0;
}