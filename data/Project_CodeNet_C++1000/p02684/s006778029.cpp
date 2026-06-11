#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    int n;
    long k;
    cin >> n >> k;
    
    vector<int> a(n,0);
    rep(i,n){
        int x;
        cin >> x;
        a[i] = x - 1;
    }
    
    if(k < n){
        int x = 0;
        rep(i,k) x = a[x];
        cout << (x + 1) << "\n";
        return 0;
    }
    
    vector<int> b(n,0);
    int y = 0, count = 0;
    while(1){
        if(b[y] > 0) break;
        b[y] = 1;
        y = a[y];
        count++;
    }
    
    int z = y, loop = 1;
    while(1){
        if(a[z] == y) break;
        z = a[z];
        loop++;
    }
    
    long kk = (k - count) % loop;
    
    rep(i,kk) y = a[y];
    
    cout << (y + 1) << "\n";

    
    return 0;
}
