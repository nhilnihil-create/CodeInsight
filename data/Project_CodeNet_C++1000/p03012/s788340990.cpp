#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w.at(i);
    int ans=50000;
    rep(i,n+1){
        int s1=0;
        int s2=0;
        rep(j,n){
            if(j<=i)s1+=w.at(j);
            else s2+=w.at(j);
        }        
        ans=min(ans,abs(s2-s1));
    }
    cout << ans << endl;
}