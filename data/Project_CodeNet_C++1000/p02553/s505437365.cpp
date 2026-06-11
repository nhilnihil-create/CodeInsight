#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;


int main (){
     ll a,b,c,d;
     cin >> a >> b >> c >> d;
     ans = b*d;
     ans = max(ans,a*d);
     ans = max(ans,b*c);
     ans = max(ans,a*c);
     cout << ans << endl;
}