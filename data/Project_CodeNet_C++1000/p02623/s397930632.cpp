#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    ll sum=0;
    int ab=0,bb=0;

    rep(i,n){
        if(sum+a[i]>k) break;
        sum+=a[i];
        ab++;
    }
    rep(i,m){
        if(sum+b[i]>k) break;
        sum+=b[i];
        bb++;
    }   
    int ans=ab+bb;
    // cout << sum << endl;

    while(true){
        if(sum+b[bb]>k){
            if(ab==0) break;
            sum-=a[ab-1];
            ab--;
        }else{
            if(bb==m) break;
            sum+=b[bb];
            bb++;
        }
        ans=max(ans,ab+bb);
        // cout << sum << ' ' << ab+bb << endl;
    }
    
    cout << ans << endl;
    return 0;
}