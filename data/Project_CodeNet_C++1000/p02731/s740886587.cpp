#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    double l;
    cin >> l;

    printf("%.10f\n", pow((l / 3.0), 3.0));

    return 0;
}
