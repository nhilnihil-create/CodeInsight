#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];
    sort(all(a));
    sort(all(b));

    int ans=0;
    if(n%2==0){
        int ax=a[n/2]+a[n/2-1];
        int bx=b[n/2]+b[n/2-1];
        ans=bx-ax+1;
    }
    else{
        int ax=a[n/2];
        int bx=b[n/2];
        ans=bx-ax+1;
    }

    cout<<ans<<endl;
}