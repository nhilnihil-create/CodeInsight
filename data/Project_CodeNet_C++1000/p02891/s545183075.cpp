#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    ll k;
    cin>>s>>k;

    int n=s.size();
    ll ans=0;
    if(k==1){
        rep(i,n-1){
            if(s[i]==s[i+1]) ans++;
        }
        cout<<ans<<endl;
        return 0;
    }

    if(s[0]!=s[n-1]){
        ll tmp=1;
        rep(i,n-1){
            if(s[i]==s[i+1]) tmp++;
            else{
                ans+=tmp/2;
                tmp=1;
            }
        }
        ans+=tmp/2;
        cout<<ans*k<<endl;
        return 0;
    }

    bool ok=true;
    rep(i,n-1){
        if(s[i]!=s[i+1]) ok=false;
    }
    if(ok){
        cout<<n*k/2<<endl;
        return 0;
    }

    ll fr=1,ba=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]) break;
        fr++;
    }
    for(int i=n-1;i>=1;i--){
        if(s[i]!=s[i-1]) break;
        ba++;
    }

    //cout<<fr<<" "<<ba<<endl;
    ans+=((fr+ba)/2)*(k-1);
    ans+=fr/2;
    ans+=ba/2;
    //cout<<ans<<endl;

    ll tmp=1;
    for(int i=fr;i<n-ba;i++){
        if(s[i]==s[i+1]) tmp++;
        else{
            ans+=(tmp/2)*k;
            tmp=1;
        }
    }
    ans+=(tmp/2)*k;
    cout<<ans<<endl;
}