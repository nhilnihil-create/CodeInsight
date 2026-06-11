#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int mx=0;
    string s,t;cin>>s>>t;
    REP(i,s.size()-t.size()+1){
        int cnt=0;
        REP(j,t.size()){
            if(s[i+j]==t[j])cnt++;
        }
        mx=max(mx,cnt);
    }
    cout<<t.size()-mx<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}