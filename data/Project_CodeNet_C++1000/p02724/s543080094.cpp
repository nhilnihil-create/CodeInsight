#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int X, x;
    cin  >> X;
    int count_500, count_5;
    count_500 = X / 500;
    count_5   = (X % 500) / 5;

    cout << (count_500 * 1000) + (count_5 * 5) << endl;

    return 0;
}
