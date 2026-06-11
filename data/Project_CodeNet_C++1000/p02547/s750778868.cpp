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

int main(){
    int n; cin>>n;
    vector<P> sai;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        P v={a,b};
        sai.push_back(v);
    }
    bool judge=false;
    rep(i,n-2){
        if(sai[i].first==sai[i].second){
            if(sai[i+1].first==sai[i+1].second){
                if(sai[i+2].first==sai[i+2].second){
                    judge=true;
                }
            }
        }
        if(judge) break;
    }
    if(judge) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}