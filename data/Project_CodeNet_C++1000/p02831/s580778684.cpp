#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    long long A, B;
    cin >> A >> B;
    long long g = gcd(A, B);
    cout << A / g * B << endl;
}