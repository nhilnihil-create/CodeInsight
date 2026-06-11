#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n; ++i)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }
    int ans=1;
    int k=0;
    for (int i=0; i<n; ++i){
        k+=c[i];
        if(k <= x) ++ans;
    }
    cout << ans << endl;
}