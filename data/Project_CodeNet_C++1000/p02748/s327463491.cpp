#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli A, B, m;
    cin >> A >> B >> m;
    vi a(A), b(B);
    lli ma = INF, mb = INF;
    rep(i,A){
        cin >> a[i];
        ma = min(ma, a[i]);
    }
    rep(i,B){
        cin >> b[i];
        mb = min(mb, b[i]);
    }
    lli ans=ma+mb;
    rep(i,m){
        lli x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans = min(ans, a[x] + b[y] - c);
    }
    out(ans);
}