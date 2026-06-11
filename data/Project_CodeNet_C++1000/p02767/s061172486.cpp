#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n;
    cin >> n;
    int sum = 0;
    int ans = 1e8;
    vector<int> x(n);
    rep(i,0,n) cin >> x.at(i);
    sort(x.begin(),x.end());
    int a = x.at(0);
    int b = x.at(n-1); 
    
    rep(p,a,b+1){
        rep(i,0,n){
            sum += (int)pow((double)x.at(i)-(double)p,2.0);
        }
        ans = min(ans,sum);
        sum = 0;
    }
    cout << ans << endl;
}