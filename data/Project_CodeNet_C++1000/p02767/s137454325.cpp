#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int mean = 0;
    rep(i,n) {
        mean += x[i];
    }
    mean /= n;
    int ans1 = 0;
    int ans2 = 0;
    rep(i,n){
        ans1 += (x[i]-mean)*(x[i]-mean);
        ans2 += (x[i]-mean-1)*(x[i]-mean-1);
    }
    int ans = min(ans1,ans2);

    cout << ans << endl;
    
}