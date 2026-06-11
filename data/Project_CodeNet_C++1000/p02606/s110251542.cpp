#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#define _USE_MATH_DEFINES
#define ll long long int
using namespace std;
//mp.reserve(1024);
//mp.max_load_factor(0.25);
bool sortit(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
       return (a.first -a.second > b.first-b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
    // freopen("mr_x_input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
	ll l,r,d;
	cin>>l>>r>>d;
	ll ans = r/d - l/d + (r%d==0&&l%d==0);
	cout<<ans<<endl;
  	return 0;
}
