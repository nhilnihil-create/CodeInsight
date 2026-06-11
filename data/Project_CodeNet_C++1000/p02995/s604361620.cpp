#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long ans = B / C - (A - 1) / C + B / D - (A - 1) / D;
    long long E = C * D / gcd(C, D);
    ans = ans - B / E + (A - 1) / E;
    cout << B - A + 1 - ans << endl;
}