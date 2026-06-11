#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int n,m;cin >> n >> m;
    n++;
    string s;cin >> s;
    vector<int> ans;
    int j=n-1;
    for(int i=n-1;i>=0;i--){
        if(j<i) continue;
        if(i==0) continue;
        int d=0;
        int rd=0;
        while(d<=m){
            if(j-d<0) break;
            if(s[j-d]=='1'){
                if(d==m) break;
                else{
                    d++;
                }
            }
            else{
                if(d==m){
                    rd=m;
                    break;
                }
                else{
                    rd=d;
                    d++;
                }
            }
        }
        j-=rd;
        if(rd!=0) ans.push_back(rd);
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    rep(i,(int)ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}