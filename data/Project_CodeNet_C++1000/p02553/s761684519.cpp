#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fill(a,b) memset(a,b,sizeof(a))

#define f first
#define s second
#define pb push_back

#define inf 1e17
#define ninf -1*1e17
#define mod 1000000007
#define N 500005
#define Ns 5005

string s;
unsigned long long int n,m,o,x,y,z,d,k,l,r;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    ll ans=0,a,b,c,d;
	    cin>>a>>b>>c>>d;
	    
	    ans= max( max(a*c,a*d),max(b*c,b*d));
	   // ans=(n==0);

	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
