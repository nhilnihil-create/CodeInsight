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
    int n,m,d; cin >> n >> m >> d;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }

    int min = pow(10,8);
    int nflag = 1;
    for(int bit = 0; bit < (1<<n);bit++){
        vector<int> x(m,0);
        int sum = 0;
        rep(i,n){
            if(bit&(1<<i)){
                sum += c[i];
                rep(j,m){
                    x[j] += a[i][j];
                }
            }
        }
        auto index = min_element(x.beg, x.end)-x.beg;
        if(x[index] >= d){
            nflag = 0;
            if(sum <= min) min = sum;
        }
    }
    if(nflag) cout << -1 << endl;
    else cout << min << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    