#include <iostream>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    ll a,b,n;
    cin >> a >> b >> n;
    ll M;
    if((b-1)>=n){
        M=floor((a*(n))/b)- a*floor((n)/b);
    }
    else{
        M=floor((a*(b-1))/b)- a*floor((b-1)/b);
    }


    cout << M;
    return 0;
}
