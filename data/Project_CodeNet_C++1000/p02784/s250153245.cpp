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
    ll h;
    int n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll sum=0;
    rep(i,n){
        sum+=a[i];
    }
    if(sum>=h){
        Yes;
    }else{
        No;
    }
}