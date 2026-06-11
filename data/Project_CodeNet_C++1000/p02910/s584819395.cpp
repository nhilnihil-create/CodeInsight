#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;

int main(){
    cin>>s;
    bool flag=true;
    rep(i,0,s.size()){
        if(i%2==0){
            if(s[i]=='L') flag=false;
        }
        else{
            if(s[i]=='R') flag=false;
        }
    }
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}
