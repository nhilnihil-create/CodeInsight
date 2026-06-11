#include <iostream>
#include<vector>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<double>a(n);
    rep(i,n) cin>>a[i];
    double ans = 1;
    double div = 0;
    rep(i,n) {
        ans *= a[i];
    }
    rep(i,n) {
        div += ans/a[i];
    }
    cout<<ans/div<<endl;

    return 0;
}
