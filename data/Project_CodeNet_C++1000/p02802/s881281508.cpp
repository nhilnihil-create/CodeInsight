#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    bool res[n];
    fill(res,res+n,false);
    vector<ll> WA(n,0);
    ll AC=0;
    rep(i,m){
        int p;string s;cin>>p>>s;
        p--;
        if(res[p]==false){
            if(s=="AC"){
                res[p]=true;
                AC++;
            }else{
                WA[p]++;
            }
        }
    }
    int WAsum=0;
    rep(i,n){
        if(res[i])WAsum+=WA[i];
    }
    cout<<AC<<" "<<WAsum<<endl;
}
