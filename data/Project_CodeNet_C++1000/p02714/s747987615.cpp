#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans=0;
    ll r,g,b;
    r=0;g=0;b=0;
    rep(i,n){
        if(s[i]=='R'){
            r++;
        }else if(s[i]=='G'){
            g++;
        }else{
            b++;
        }
    }
    ans=r*g*b;
    //cout << ans ;

    rep(i,n-2){
        for(ll k=1;i+k+k<n;++k){
            if(s[i]!=s[i+k]&&s[i]!=s[i+2*k]&&s[i+k]!=s[i+2*k]){
                ans--;
            }
        }
    }
    cout << ans << endl;
}