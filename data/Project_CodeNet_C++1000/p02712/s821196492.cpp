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

int main(){
    
    long n, ans = 0;
    cin >> n;
    
    rep(i,n+1){
        if(i % 3 > 0 && i % 5 > 0) ans += i;
    }
    
    cout << ans << "\n";
    
    return 0;
}

