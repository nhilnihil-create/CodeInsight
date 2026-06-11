// Winners don't quit and Quitters don't win
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mod 998244353
#define MAX 100005
int main()
{

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x,y,i,limit1,limit2;
    vll a,b;
    cin>>n;
    for(i=0;i<n;++i){
    	cin>>x>>y;
    	a.pb(x);
    	b.pb(y);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(n%2){
        limit1 = a[n/2];
        limit2 = b[n/2];
        cout<<(limit2-limit1+1);
    }
    else{
    	x = n/2;
    	limit1 = (a[x] + a[x-1]);
    	limit2 = (b[x] + b[x-1]);
    	cout<<(limit2 - limit1 + 1);
    }
}
