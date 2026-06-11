#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;
long C = 1e18;

int main(){
    
    int n;
    cin >> n;

    vector<long> a(n, 0);
    long ans = 1;
    
    rep(i,n){
        cin >> a[i];
        if(a[i] == 0){
            cout << 0 << "\n";
            return 0;
        }
    }
    
    rep(i,n){
        if (a[i] > C / ans){
            cout << -1 << "\n";
            return 0;
        }
        ans *= a[i];
    }
    
    cout << ans << "\n";
    
    return 0;
}

