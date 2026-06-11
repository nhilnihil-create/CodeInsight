#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll N;
    cin >> N;
    if(N % 2 == 0){cout << N / 2 << endl;return 0;}
    else{cout  << N / 2 + 1 << endl;return 0 ;}

    return 0;
}
