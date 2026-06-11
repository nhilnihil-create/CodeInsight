#include <iostream>
using namespace std;
int gcd(int x,int y){
    if(x < y) swap(x,y);
    if(y == 0) return x;
    else return gcd(y,x%y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a,b; cin >> a >> b;
    int c,d; cin >> c >> d;
    long long lcm = (long long)c*d/gcd(c,d);
    long long bNum = b - b/d - b/c + b/lcm;
    long long aNum = a-1 - (a-1)/d - (a-1)/c + (a-1)/lcm;
    cout << bNum - aNum << endl;
    return 0;
}