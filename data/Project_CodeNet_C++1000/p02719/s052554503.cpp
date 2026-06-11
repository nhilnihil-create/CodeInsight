#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll N, K;
    cin >> N >> K;

    ll per;

    per = N / K;

    ll n, p;
    n = N - ((per + 1) * K);
    p = N -  (per      * K);

    if(abs(n) > abs(p)){cout << p << endl;}
    else{cout << n * (-1) << endl;}


    return 0;
}
