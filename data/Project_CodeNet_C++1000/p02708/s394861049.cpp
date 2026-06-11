#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
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
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli mod=1000000007;
    lli ans=0;
    lli n,k;
        cin>>n>>k;
    vi sum(n+1);

    sum[0]=0;
    rep(i,n){
        sum[i+1]=sum[i]+i+1;
    }
    for(int j=k;j<=n;j++){
        ans+=(sum[n]-sum[n-j])-sum[j-1]+1;
        ans%=mod;
    }
    ans+=1;
    ans%=mod;
    out(ans);

}