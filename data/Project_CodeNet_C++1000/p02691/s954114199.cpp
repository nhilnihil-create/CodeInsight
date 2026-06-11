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
    
    long n;
    cin >> n;
    
    vector<long> a(n,0);
    map<int, int> m;
    
    rep(i,n){
        cin >> a[i];
        m[i - a[i]]++;
    }
    
    long ans = 0;
    
    rep(i,n) ans += m[i + a[i]];
    
    cout << ans << "\n";
    
    return 0;
}

