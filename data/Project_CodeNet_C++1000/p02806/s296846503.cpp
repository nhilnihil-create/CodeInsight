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
    vector<string> s(n);vector<int> t(n);
    string x;
    rep(i,n)cin >> s[i] >> t[i];
    cin >> x;
    int a;
    rep(i,n){
        if(x==s[i]){
            a=i;
        }
    }
    int ans=0;
    for(int i=a+1;i<n;++i){
        ans+=t[i];
    }
    cout << ans << endl;
}