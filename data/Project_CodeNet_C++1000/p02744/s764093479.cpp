#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int n;
void dfs(int i,int k,string s){
    if(i==n){
        cout<<s<<endl;
        return;
    }
    rep(j,k){
        char x=j+'a';
        string t=s;
        t.push_back(x);
        dfs(i+1,k,t);
    }
    char x=k+'a';
    s.push_back(x);
    dfs(i+1,k+1,s);
    return;
}
int main(void){
    cin>>n;
    dfs(0,0,"");
}