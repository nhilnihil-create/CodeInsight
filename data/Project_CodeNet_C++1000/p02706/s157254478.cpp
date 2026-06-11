
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
    
    int n, m;
    cin >> n >> m;
    
    rep(i,m){
        int a;
        cin >> a;
        n -= a;
        if(n < 0){
            cout << -1 << "\n";
            return 0;
        }
    }
    
    cout << n << "\n";
    
    return 0;
}

