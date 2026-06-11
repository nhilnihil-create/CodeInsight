//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    ll ans=0,p=-1,n=s.size()+1;
    vector<ll> a(n,0);
    rep(i,n-1){
        if(s[i]=='<'){
            a[i]=p+1; p++;
        }
        else{
            a[i]=p+1; p=-1;
        }
    }
    if(s[n-2]=='<') a[n-1]=p+1;
    p=-1;
    rep(i,n-1){
        if(s[n-2-i]=='>'){
            a[n-1-i]=max(a[n-1-i],p+1); p++;
        }
        else{
            a[n-1-i]=max(a[n-1-i],p+1); p=-1;
        }
    }
    if(s[0]=='>') a[0]=p+1;
    rep(i,n) ans+=a[i];
    cout<<ans<<endl;
}