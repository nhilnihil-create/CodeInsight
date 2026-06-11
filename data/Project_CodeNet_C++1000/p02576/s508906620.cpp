#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, X, T;
    cin >> N >> X >> T;
    if(N % X != 0){
        cout << ((N / X) + 1) * T << endl;
    }
    else{cout << ( N / X ) * T << endl;}

    return 0;
}
