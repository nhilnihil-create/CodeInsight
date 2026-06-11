#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n){
        cin>>s[i];
        sort(all(s[i]));
    }

    sort(all(s));

    ll ans=0;
    ll cnt=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            ans+=cnt*(cnt-1)/2;
            cnt=1;
        }
        else cnt++; 
    }
    ans+=cnt*(cnt-1)/2;

    cout<<ans<<endl;
}
