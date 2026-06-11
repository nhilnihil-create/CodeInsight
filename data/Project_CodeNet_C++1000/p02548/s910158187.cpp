#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n; cin>>n;
ll ans=0;
for(int i=1; i<=n;i++){
 ans =ans+(n-1)/i; 
}

cout<<ans;
  return 0;
}