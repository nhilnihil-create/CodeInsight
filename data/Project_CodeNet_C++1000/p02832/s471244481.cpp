#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() { 
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    int j=1;
    int ans=0;
    bool flag=false;
    rep(i,n){
        if(a.at(i)!=j)ans++;
        else{
            flag=true;
            j++;
        }
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
}