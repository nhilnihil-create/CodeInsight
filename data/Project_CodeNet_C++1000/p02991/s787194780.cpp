#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,n) for(lli i=0;i<n;i++)
#define repb(i,n) for(lli i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define bg() begin()
#define en() end()
#define ft first
#define sc second
#define vect_lli_it vector<lli>::iterator
#define set_lli_it set<lli>::iterator
#define inf 1e18
#define all(X) X.begin(),X.end()
#define iterate(X) for(it=X.begin();it!=X.end();it++)
lli combi(lli n,lli k)
{
    lli ans=1;
    k=k>n-k?n-k:k;
    lli j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
lli findlcm(vector <lli> arr, lli n)
{
    lli ans = arr[0];
    for (lli i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m;
    cin>>n>>m;
    vector <vector<lli> > vect(n+1);
    lli u,v;
    rep(i,m){
    	cin>>u>>v;
    	vect[u].pb(v);
	}
	lli s,t;
	cin>>s>>t;
	lli dis[n+1][3];
	for(lli i=1;i<=n;i++){
		for(lli j=0;j<3;j++)
		dis[i][j]=inf;
	}
	dis[s][0]=0;
	priority_queue <pair<lli,lli>, vector <pair<lli,lli> >,greater<pair<lli,lli> > >q;
	q.push(mp(0,s));
	while(!q.empty()){
		pair <lli,lli> p=q.top();
		q.pop();
		lli t=(p.ft+1)%3;
		for(lli i=0;i<vect[p.sc].size();i++){
			if(dis[vect[p.sc][i]][t]> (p.ft+1)){
				dis[vect[p.sc][i]][t]=p.ft+1;
				q.push(mp(p.ft+1,vect[p.sc][i]));
			}
		}
	}
	if(dis[t][0]==inf)
	cout<<"-1\n";
	else
	cout<<dis[t][0]/3;
    return 0;
}
