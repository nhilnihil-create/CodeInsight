#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    string s;
    int k;
    cin>>s>>k;
    if(s.length()==1){
        cout<<k/2<<endl;
        return 0;
    }
    ll cnt=1,ans=0;
    bool judge=true;
    rep(i,s.length()){
        if(s[i]==s[i+1])cnt++;
        else{
            ans+=cnt/2;
            cnt=1;
            if(i<s.length()-1)judge=false;
        }
    }

    ans=ans*k;

    if(s[0]==s[s.length()-1]){
        ll a=0,b=0;
        for(;;a++)if(s[a]!=s[a+1])break;
        for(int i=s.length()-1;;i--)if(s[i-1]!=s[i])break;else b++;
        a++;b++;
        //cout<<a<<" "<<b <<endl;
        if(a==s.length())ans=(ll)(a*k)/2;
        else ans-=(a/2+b/2-(a+b)/2)*(k-1);
    }
    cout<<ans<<endl;

    return 0; 
}
