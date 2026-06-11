#include<bits/stdc++.h>
using namespace std;
// ---------------------------------------------------------------------------
/* */
// ---------------------------------------------------------------------------

#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fi(a,b) for(int i=a;i<=b;++i)
#define fj(a,b) for(int j=a;j<=b;++j)
#define all(x) x.begin(),x.end()
// #define int long long

// ---------------------------------------------------------------------------
// Global Variables
const int mod = 1e9+7;
const int maxn = 2e5 + 9;

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void test_case(int tc)
{
	// cout<<"Case #"<<tc<<": ";
	int k;cin>>k;
	string s = "ACL";
	fi(1,k)cout<<s;
}

int32_t main()
{
	FASTIO;
	#ifndef ONLINE_JUDGE
		freopen("/home/suryakant/input.txt","r",stdin);
		freopen("/home/suryakant/output.txt","w",stdout);
	#endif
	
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}