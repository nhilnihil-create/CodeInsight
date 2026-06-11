//---------------------------------------------------------MANAS UNIYAL---------------------------------------------------------
//                                                        NEVER  GIVE  UP
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define ll long long
#define pb push_back
#define fi first 
#define se second
#define pii pair<ll,ll>
#define INF 0x3f3f3f3f
#define LINF 98765432123456789
#define testcases() ll t; cin>>t; while(t--)
#define debug cout<<"Hello\n";
#define debug1(x) cout<<#x<<" "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<"\n";
#define debug4(w,x,y,z) cout<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<"\n";
#define rep(i,start,end) for(ll i=start;i<end;i++)
#define sz(x) (ll)((x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
//------------------------------------------------------------------------------------------------------------------------------

int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/DELL/Desktop/input.txt", "r", stdin);
	#endif

	fast;
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max({a*c,a*d,b*c,b*d});
	return 0;
}
