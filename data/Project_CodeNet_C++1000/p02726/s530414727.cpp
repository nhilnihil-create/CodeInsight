#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 11711711

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> dist(n);
    rep(i,n){
        dist[i]=0;
    }
    int dist_val;
    FOR(i,n+1,1){
        FOR(j,n+1,1){
            dist_val=min(abs(j-i),abs(j-x)+1+abs(i-y));
            dist_val=min(dist_val,abs(i-x)+1+abs(j-y));
            dist[dist_val]++;
        }
    }
    rep(i,n){
        dist[i]/=2;
    }
    FOR(i,n,1){
        cout << dist[i] << endl;
    }
}