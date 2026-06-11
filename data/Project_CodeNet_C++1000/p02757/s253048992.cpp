#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,p;
string s;
map<int,ll> mp;
int pp[200001];
int main(){
    cin>>n>>p>>s;
    ll ans=0,cur=0;
    int p10=1;
    if(p==2||p==5)rep(i,n){
        cur=(cur*10+(s[i]-'0'))%p;
        if(p==2||p==5){
            if(cur%p==0)ans+=i+1;
        }
    }
    else{
        for(int i=n;i>=0;--i){
            ans+=mp[pp[i]];
            ++mp[pp[i]];
            if(i>0)pp[i-1]=(pp[i]+p10*(s[i-1]-'0'))%p;
            p10*=10,p10%=p;
        }
    }
    cout<<ans<<endl;
    return 0;
}