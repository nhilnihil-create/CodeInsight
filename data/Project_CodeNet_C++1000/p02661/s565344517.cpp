#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    if(n % 2 == 1){
        int ind = (n-1)/2;
        ans = b[ind] - a[ind] + 1;
    }else{
        int ind = n/2;
        ans = (b[ind]+b[ind-1]) - (a[ind]+a[ind-1]) + 1;
    }

    cout << ans << endl;
}