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
    
    long x, money = 100;
    cin >> x;
    
    long ans = 0;
    
    while(money < x){
        ans++;
        money += money / 100;
    }
    
    cout << ans << "\n";
    
    return 0;
}

