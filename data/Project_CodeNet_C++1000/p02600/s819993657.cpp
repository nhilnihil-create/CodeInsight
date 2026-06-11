#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int x;cin>>x;
    if(x<600)x=8;
    else if(x<800)x=7;
    else if(x<1000)x=6;
    else if(x<1200)x=5;
    else if(x<1400)x=4;
    else if(x<1600)x=3;
    else if(x<1800)x=2;
    else x=1;
    cout<<x<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}