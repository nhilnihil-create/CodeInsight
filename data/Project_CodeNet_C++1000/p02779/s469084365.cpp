#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    sort(all(a));
    bool ok = true;
    rep(i,n-1){
        if(a[i]==a[i+1])ok = false;
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}