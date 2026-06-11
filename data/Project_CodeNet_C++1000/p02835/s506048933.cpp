#include<bits/stdc++.h>

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FOD(i,b,a) for(i=a;i>=b;i--)
#define pa pair<int,int>
#define fi first
#define se second
#define task "x"

typedef long long ll;
const ll M=1e6+1;
const ll N=1e4+1;
using namespace std;

ll i, j, n, ans = 0, x, y, z;
string s;

void input()
{
    cin >> x >> y >> z ;

}

void solve()
{
    if(x + y + z>=22) cout<<"bust";
    else cout<<"win";
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

