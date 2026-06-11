#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int x,n,cur=1e9,ans=-1;
    cin >> x >> n;
    map<int,int> p;
    rep(i,n){
        int a;
        cin >> a;
        p[a]++;
    }
    rep(i,102){
        if(p[i]) continue;
        if(abs(x-i) < cur){
            cur = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;
}
