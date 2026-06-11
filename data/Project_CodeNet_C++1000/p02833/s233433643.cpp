#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

int main()
{
    ll n;
    cin >> n;
    ll ans=0;
    ll five=10;
    if(n%2==1){
        ans=0;
    }else{
        while(n>=five){
            ans+=n/five;
            five*=5;
        }
    }

    cout << ans << endl;
}