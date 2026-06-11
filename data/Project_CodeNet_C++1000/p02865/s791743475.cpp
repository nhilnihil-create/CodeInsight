#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
ios::sync_with_stdio(false);
cin.tie(0);

int n;
cin>>n;
int ans;
if(n&1==0)ans=n/2-1;
else ans=(n+1)/2-1;
cout<<ans<<endl;
return 0;
}