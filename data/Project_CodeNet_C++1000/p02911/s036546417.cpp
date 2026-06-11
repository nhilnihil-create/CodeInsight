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
    int n,k,q;
    cin >> n >> k >> q;
    int a[n]={0};
    REP(i,q){
        int x;
        cin >> x;
        --x;
        a[x]++;
    }
    int border=q-k+1;
    REP(i,n){
        if(a[i]>=border)cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}