#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
string s;

int main(){
    cin>>n>>s;
    int cnt=0;
    rep(i,0,n-1){
        if(s[i+1]!=s[i]) cnt++;
    }
    cnt++;
    cout<<cnt<<"\n";
    return 0;
}
