#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    int n,m;
    cin >> n >> m;
    int h[n];
    REP(i,n) cin >> h[i];
    vector<int> to[100010];
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int cnt=0;
    REP(i,n){
        bool flag=true;
        for(int v : to[i]){
            if(h[i]<=h[v]){
                flag=false;
                break;
            }
        }
        if(flag) cnt++;
    }

    cout << cnt;

    return 0;
}