#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define beg begin()
#define end end()

void _main(){
    int n,m; cin >> n >> m;
    vector<int> h(n);
    vector<vector<int>> g; g.resize(n);
    rep(i,n) cin >>h[i];
    rep(i,m){
        int a,b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto goodcheck = [&](int& i,int& x){
        for(auto y:g[i]){
            if(x <= h[y]) return false;
        }
        return true;
    };
    int count=0;
    rep(i,n){
        int x = h[i];
        if(goodcheck(i,x)) count++;
    }
    cout << count << endl;
    
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    