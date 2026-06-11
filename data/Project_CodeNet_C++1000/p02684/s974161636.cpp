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
    int n;ll k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    
    vector<int> s;
    vector<int> ord(n+1,-1);
    int c=1, l=0;
    {
        int v=1;
        while(ord[v]==-1){
            ord[v]=s.size();
            s.push_back(v);
            v=a[v-1];
        }
        c=s.size()-ord[v];
        l=ord[v];
    }
    if(k<l) cout << s[k] << endl;
    else{
        k-=l;
        k%=c;
        cout << s[l+k] << endl;
    }

    return 0;
}