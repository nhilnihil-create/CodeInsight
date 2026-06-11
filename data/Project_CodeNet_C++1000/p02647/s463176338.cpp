#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> c(n,n);
    rep(i,n){
        cin >> a[i];
    }
    rep(j,k){
        vector<int> d(n+1);
        rep(i,n){
            d[max(i-a[i],0)]++;
            d[min(i+a[i]+1,n)]--;
        }
        vector<int> e(n,d[0]);
        rep(i,n-1){
            e[i+1]=e[i]+d[i+1];
        }
        a=e;
        if (c==e){
            break;
        }
    }
    rep(i,n-1){
        cout << a[i] << ' ';
    }
    cout << a[n-1] << endl;
    return 0;
}
