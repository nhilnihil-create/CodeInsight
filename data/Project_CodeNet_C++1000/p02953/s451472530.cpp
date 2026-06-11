#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    ll tmp;cin>>tmp;tmp--;
    rep(i,n-1){
        ll h;cin>>h;
        if(tmp>h){
            cout<<"No"<<endl;
            return 0;
        }
        if(tmp<=h-1)tmp=h-1;
    }
    cout<<"Yes"<<endl;
}