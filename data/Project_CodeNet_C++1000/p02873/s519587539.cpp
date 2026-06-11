#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s;
    cin>>s;
    int n=s.size();
    
    ll r=0,l=0,ans=0;
    rep(i,n-1){
        if(s[i]=='>' && s[i+1]=='<'){
            l++;
            ll a=max(r,l);
            ll b=min(r,l)-1;
            ans+=a*(a+1)/2;
            ans+=b*(b+1)/2;
            r=0,l=0;
        }
        else if(s[i]=='>') l++;
        else r++;
    }
    if(s[n-1]=='<') r++;
    else l++;

    ll a=max(r,l);
    ll b=min(r,l)-1;
    ans+=a*(a+1)/2;
    ans+=b*(b+1)/2;



    cout<<ans<<endl;
    
}


