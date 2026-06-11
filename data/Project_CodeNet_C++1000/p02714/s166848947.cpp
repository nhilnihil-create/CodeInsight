#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    string s;
    cin>>n>>s;
    
    ll r=0,g=0,b=0;
    rep(i,n){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }

    ll ans=r*g*b;
    ll sub=0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) continue;
            int k=j+j-i;
            if(k>=n || s[k]==s[j] || s[k]==s[i]) continue;
            sub++;
        }
    }
    cout<<ans-sub<<endl;
}