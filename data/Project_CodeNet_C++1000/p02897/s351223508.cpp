#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#include<tuple>
#include<bitset>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << fixed << setprecision(7) << (x) << endl;
#define printbit(x) cout << bitset<15>(x) << endl;
using ll = long long int;



long double pi = 3.14159265359;

int n;

int main(){
    cin >> n;
    long double ans;
    long double nn = (long double)n;
    if(n == 1) {
        printfloat(1);
        return 0;
    }
    if(n%2) ans = (n/2+1)/nn;
    else ans = (nn/2)/nn;
    printfloat(ans);

return 0;
}