#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    unsigned long long X,a;
    int i;
    cin >> X;
    a = 100;
    for(i=0;i<3761;i++){
        if(a >= X){cout << i << endl;return 0;}
        else{a += a / 100;}
    }

    return 0;
}
