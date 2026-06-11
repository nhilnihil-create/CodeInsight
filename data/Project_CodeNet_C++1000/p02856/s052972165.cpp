#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 900000000000000004
signed main(void){
    int n;cin>>n;
    int c=0,d=0;
    rep(i,n){
        int d0,c0;cin>>d0>>c0;
        c+=c0;
        d+=c0*d0;
    }
    cout<<c-1+(d-1)/9<<endl;
}
        
