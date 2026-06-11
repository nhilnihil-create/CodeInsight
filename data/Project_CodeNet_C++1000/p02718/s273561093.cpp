#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    rep(i,n) {   
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    double lim = (double)sum/4.0/m;
    rep(i,n){
        if((double)a[i] >= lim) ans++;
    }
    if(ans >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}