#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int n,m,q;
vector<int> a(51),b(51),c(51),d(51);
int dfs(int i,int j,vector<int>& A){
    if(i==n){
        int res=0;
        rep(k,q){
            if(A[b[k]]-A[a[k]]==c[k])res+=d[k];
        }
        return res;
    }
    
    int res=0;
    for(int k=j;k<=m;k++){
        auto nA=A;
        nA.push_back(k);
        int buf=dfs(i+1,k,nA);
        chmax(res,buf);
    }
    return res;
}
int main(void){
    cin>>n>>m>>q;
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;b[i]--;
    }
    vector<int> A;
    int res=dfs(0,1,A);
    cout<<res<<endl;
}