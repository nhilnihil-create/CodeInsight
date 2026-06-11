#include <iostream>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    long double a,b,c;
    cin >> a >> b >> c;
    if(a + b + 2 * sqrt(a * b) < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}