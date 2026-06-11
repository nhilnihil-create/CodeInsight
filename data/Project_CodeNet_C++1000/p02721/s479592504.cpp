#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,c;cin >> n >> k >> c;
    string s;cin >> s;
    vector<int> sl(n+1),sr(n+1);
    rep(i,n){
        if(s[i]=='o'){
            sl[i+1]=sl[max(0,i-c)]+1;
        }
        else{
            sl[i+1]=sl[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='o'){
            sr[i]=sr[min(n,i+c+1)]+1;
        }
        else{
            sr[i]=sr[i+1];
        }
    }
    rep(i,n){
        if(sl[i]+sr[i+1]<k&&s[i]=='o'){
            cout << i+1 << endl;
        }
    }
}