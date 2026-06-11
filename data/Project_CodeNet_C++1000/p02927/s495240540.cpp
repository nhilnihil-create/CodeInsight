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
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli m, d;
    cin >> m >> d;
    lli ans = 0;
    rep(i,m){
        rep(j,d){
            lli t = (j + 1) / 10;
            lli o = (j + 1) % 10;
            if(t*o==i+1&&o>1&&t>1)
                ans++;
        }
    }
    out(ans);
}