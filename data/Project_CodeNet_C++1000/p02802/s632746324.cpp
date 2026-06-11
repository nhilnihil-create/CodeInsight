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
    int n,m,w=0,ans=0; cin>>n>>m;
    map<int,int> se;
    rep(i,m){
        int p; string s; cin>>p>>s;
        if(s=="AC"){
            if(se.count(p)){
                if(se[p]!=-1){
                    w+=se[p]; ans++;
                }
            }
            else ans++;
            se[p]=-1;
        }
        else{
            if(!(se.count(p))){
                se[p]=1;
            }
            else{
                if(se[p]!=-1) se[p]++;
            }
        }
    }
    cout<<ans<<" "<<w<<endl;
}