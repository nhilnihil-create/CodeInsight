/* Author - thiolhub */

#include <bits/stdc++.h>

using namespace std;

#define ll              long long int
#define ld              long double
#define db              double
#define pi              3.1415926535897932384626
#define PI              acos(-1.0)
#define endl            "\n"
#define mod             1000000007
#define mk              make_pair
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            ll t; cin>>t; while(t--)
#define sc(a)	        scanf("%lld",&a);
#define pr(a)	        printf("%lld\n",a)
#define rep(i,a,n)		for(ll i=a;i<n;i++)
#define m(a)		    memset(a,0,sizeof(a))
#define FastIO          ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define min3(a,b,c)     min(a,min(b,c))


int main(){ FastIO;

int i,n,q,k;
cin>>n>>k>>q;
int a[n];
for(i=0;i<n;i++) a[i]=k-q;
while(q--){
	int b;cin>>b;
	a[b-1]++;
}
for(i=0;i<n;i++){
	if(a[i]>0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
}