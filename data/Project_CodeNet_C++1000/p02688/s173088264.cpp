#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (int) 1e9 + 7;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n,0);
    
    rep(i,k){
        int d;
        cin >> d;
        rep(j,d){
            int b;
            cin >> b;
            a[b - 1]++;
        }
    }
    
    int ans = 0;
    
    rep(i,n) if(a[i] == 0) ans++;
    
    cout << ans << "\n";
    
    return 0;
}

