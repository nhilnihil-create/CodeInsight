#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;
    
    ll H[n];
    rep(i,n)    cin >> H[i];

    if(n==1){
        cout << 0 << endl;
        return 0;
    }

    int ans(0),sum(0);
    for(int i=1;i<n;i++){
        if(H[i]<=H[i-1]){
            sum++;
        }else{
            ans = max(ans,sum);
            sum = 0;
        }
    }

    ans = max(ans,sum);

    cout << ans << endl;

    return 0;
}