#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int n,m,q;
int query[55][4];

ll score(vector<int> &A) {
    ll ret = 0;
    rep(i,q) {
        if(A[query[i][1]-1] - A[query[i][0]-1] == query[i][2]) ret += query[i][3];
    }
    return ret;
}

ll dfs(vector<int> &A) {
    if(A.size() == n) {
        return score(A);
    }
    ll ret=0;
    int last;
    if(A.size()==0) last = 1;
    else last = A[A.size()-1];

    for(int i = last;i<=m;i++) {
        A.push_back(i);
        ret = max(ret,dfs(A));
        A.pop_back();
    }
    return ret;
}

int main() {
    // int n,m,q;
    cin>>n>>m>>q;
    // int query[55][4];
    rep(i,q) {
        rep(j,4) {
            cin>>query[i][j];
        }
    }
    vector<int> A;
    cout<<dfs(A)<<endl;
}