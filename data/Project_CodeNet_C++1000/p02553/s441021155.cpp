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

long MAX(long x, long y){
    if(x > y){
        return x;
    } else {
        return y;
    }
}

int main(){
    
    long a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    
    ans = MAX((a*c), MAX((a*d), MAX(b*c, b*d)));
    
    cout << ans << "\n";
    
    return 0;
}

