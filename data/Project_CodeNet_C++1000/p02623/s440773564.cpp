#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 100000

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1),b(m+1);
    rep(i,n)cin >> a[i+1];
    rep(i,m)cin >> b[i+1];

    rep(i,n){
        a[i+1]+=a[i];
    }
    rep(i,m){
        b[i+1]+=b[i];
    }
    int ans=0;int lim_b=0;int p,q;p=0;q=0;
    ll tmp=0;
    int i=0;
    while(a[i]<=k&&i<=n){
        ++i;
    }
    ans=i-1;tmp=a[ans];
    i=0;
    while(b[i]<=k&&i<=m){
        ++i;
    }
    lim_b=i-1;
    p=ans;
    rep(i,lim_b+1){
        if(a[p]+b[i]>k){
            ans=max(p+i-1,ans);
            while(a[p]+b[i]>k){
                p--;
                if(p==0){
                    break;
                }
            }    
        }
        if(p==0&&a[p]+b[i]>k){
            break;
        }
        if(i==lim_b&&a[p]+b[i]<=k){
            ans=max(p+i,ans);
        }
    }
    cout << ans << endl;


    
}