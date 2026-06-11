#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int N,M,Q;
vector<int> a,b,c,d;
ll score(const vector<int> &A){
    int ans=0;
    rep(i,Q){
        if(A[b[i]]-A[a[i]]==c[i]) ans+=d[i];
    }
    return ans;
}

ll dfs(vector<int> &A){
    int num=A.size();
    if(num==N){
        return score(A);
    }

    int p=(A.empty()?0:A.back());
    ll res=0;
    for(int v=p; v<M; v++){
        A.push_back(v);
        res=max(res,dfs(A));
        A.pop_back();

    }
    return res;
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i,Q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> A;
    cout<<dfs(A)<<endl;
}