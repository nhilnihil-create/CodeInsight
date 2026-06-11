#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll A = max(a*c, a*d);
    ll B = max(b*c, b*d);
    cout << max(A,B) << endl;
    return 0;

}
