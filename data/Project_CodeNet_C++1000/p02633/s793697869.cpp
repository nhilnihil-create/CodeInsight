#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define beg begin()
#define end end()
int gcd(int a, int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
void _main(){
    int x; cin >> x;
    int k = lcm(x,360)/x;
    cout << k << endl;
    
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    