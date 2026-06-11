#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
long lcm(long long a,long long b){
    return a/gcd(a,b)*b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    cout << lcm(a,b) << endl;
    return 0;
}