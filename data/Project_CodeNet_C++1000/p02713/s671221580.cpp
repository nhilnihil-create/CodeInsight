#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

long fun(long a, long b){
    if ((a % b) == 0) return b;
    return fun(b, a % b);
}

int main(){
    
    long n;
    cin >> n;
    
    long ans = 0;
    
    for(long i = 1; i <= n; i++)
        for(long j = 1; j <= n; j++)
            for(long k = 1; k <= n; k++)
                ans += fun(fun(i, j), k);
    
    cout << ans << "\n";
    
    return 0;
}
