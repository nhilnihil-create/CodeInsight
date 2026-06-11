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
    string s;
    cin >> s;
    int n = s.size();
    bool ck = true;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(s.at(i) != 'h'){
                ck = false;
                break;
            }
        }
        else if(s.at(i) != 'i'){
            ck = false;
            break;
        }
    }
    if(n % 2 != 0) ck = false;
    if(ck) cout << "Yes" << endl;
    else cout << "No" << endl;
    solve();
    return 0;
}

