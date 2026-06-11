#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){

    int n, l; cin >> n >> l;
    vector<int>a(n);

    rep(i,n) a[i] = l+i;

    if(l<=0){
        if(n+l-1<=0){
            a[n-1]=0;
        } else {
        }
    } else {
        a[0]=0;
    }

    int ans=0;

    rep(i,n) ans += a[i];

    cout << ans << endl;

    return 0;
}