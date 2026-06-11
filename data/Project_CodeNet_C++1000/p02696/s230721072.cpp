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
    
    long a, b, n, ans;
    cin >> a >> b >> n;
    
    if(n < b){
        ans = (long) a * n / b;
    } else {
        ans = (long) a * (b - 1) / b;
    }
    
    cout << ans << "\n";
    
    return 0;
}

