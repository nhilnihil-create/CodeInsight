#include<bits/stdc++.h>
#define N 200050
#define M 200
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
#define MOD mod
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int l,r,d;
    cin>>l>>r>>d;
    int ans = r/d;
    if(l)ans -= (l-1)/d;
    cout<<ans;
  	return 0;
}

