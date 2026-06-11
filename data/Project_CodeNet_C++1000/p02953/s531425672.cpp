#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    ll maxi=0;
    rep(i,n){
       ll h;cin>>h;
       if(h==maxi)continue;
       else if(chmax(maxi,h))maxi--;
       else{
           cout<<"No"<<endl;
           return 0;
       }
    }
    cout<<"Yes"<<endl;
}