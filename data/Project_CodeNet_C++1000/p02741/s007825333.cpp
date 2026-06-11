#include "bits/stdc++.h"
#include <math.h>
#include <time.h>
using namespace std;
const long long mod = 1000000007;
#define ll long long
#define P pair<int, int>
#define dump(x)                             \
    if (dbg) {                              \
        cout << #x << " = " << (x) << endl; \
    }
bool dbg = false;
long long gcd(long long a, long long b){
   if (a % b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a % b));
   }
}
long long lcm(long long a, long long b){
   return (a / gcd(a, b))* b;
}
//---------------------------------------------------------------------------------------------------
/*ここからいじる*/
//---------------------------------------------------------------------------------------------------

void solve(){
}
int main(){
    vector<int>an(32);
    for(int i = 0; i < 32; i++){
        an.at(i) = 1;
    }
    an.at(3) = 2;
    an.at(5) = 2;
    an.at(7) = 5;
    an.at(8) = 2;
    an.at(9) = 2;
    an.at(11) = 5;
    an.at(13) = 2;
    an.at(15) = 14;
    an.at(17) = 5;
    an.at(19) = 5;
    an.at(20) = 2;
    an.at(21) = 2;
    an.at(23) = 15;
    an.at(24) = 2;
    an.at(25) = 2;
    an.at(26) = 5;
    an.at(27) = 4;
    an.at(29) = 4;
    an.at(31) = 51;
    int k;
    cin >> k;
    k--;
    cout << an.at(k) << endl;

    solve();
    return 0;
}

