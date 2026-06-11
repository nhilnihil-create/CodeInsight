//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m=0; cin>>n;
    map<string,int> M;
    rep(i,n){
        string s; cin>>s;
        if(!(M.count(s))) M[s]=0;
        M[s]++; m=max(m,M[s]);
    }
    vector<string> ans;
    for(auto p:M){
        if(m==p.second) ans.push_back(p.first);
    }
    sort(al(ans));
    rep(i,ans.size()) cout<<ans[i]<<endl;
}