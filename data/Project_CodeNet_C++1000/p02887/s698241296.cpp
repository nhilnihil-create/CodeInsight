#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n,ans(0);
    char t('0');
    cin >> n >> t;
    rep(i,n-1){
        char c; cin >> c;
        if(c!=t){
            ans++;
            t = c;
        }
    }

    cout << ans+1 << endl;

    return 0;
}