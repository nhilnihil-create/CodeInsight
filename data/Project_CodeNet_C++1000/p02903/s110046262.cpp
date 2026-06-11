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
    lli h,w,a,b;
    cin>>h>>w>>a>>b;
    vvi ans(h,vi(w,1));
    rep(i,a){
        rep(j,b){
            ans[j][i]=0;
        }
    }
    rep(i,h-b){
        rep(j,w-a){
            ans[h-i-1][w-j-1]=0;
        }
    }
    rep(i,h){
        rep(j,w){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}