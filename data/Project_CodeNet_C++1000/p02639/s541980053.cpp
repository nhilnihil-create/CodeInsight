#include<bits/stdc++.h>

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FOD(i,b,a) for(i=a;i>=b;i--)
#define pa pair<long long , long long >
#define pb push_back
#define fi first
#define se second
#define task "x"

typedef long long ll;
const ll M=1e6 + 1;
const ll N=1e4 + 1;
const ll MOD = 1e9 + 1;
using namespace std;

ll a[6],i;

void input()
{
 cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
}

void solve()
{
FOR(i,1,5) if(a[i] == 0) {cout<< i;break;}
}

int main()
{
  	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	if(fopen(task".inp","r"))
        {
 	  freopen(task".inp","r",stdin);
 	  freopen(task".out","w",stdout);
	}
 	input();
	solve();

   return 0;
}
