#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
const ll mod = 1e+9;
using namespace std;
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
int main(){
    int a,b;    cin >> a >> b;
    cout << (6-(a+b)) << "\n";
return 0;
}