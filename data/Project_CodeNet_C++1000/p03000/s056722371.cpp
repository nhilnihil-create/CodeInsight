
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> l(n+1);
    l[0]=0;
    rep(i,n){
        int x;
        cin >> x;
        l[i+1]=l[i]+x;
    }

    int ans=0;
    for(int i=0; i<=n; i++){
        if(l[i]<=x){
            ans ++;
        }
    }
    cout << ans << endl;
}