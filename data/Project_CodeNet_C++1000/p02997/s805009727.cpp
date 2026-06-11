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
    lli n,k;
    cin>>n>>k;
    if(k>((n-1)*(n-2))/2)
    cout<<"-1";
    else{
    vector <pair<lli,lli> > vect;
    rep(i,n-1){
    	vect.pb(mp(1,i+2));
	}
	lli j=2;
	lli loop=((n-1)*(n-2))/2-k;
	while(loop>0){
		for(lli p=j+1;p<=n && loop>0;p++){
			vect.pb(mp(j,p));
			loop--;
		}
		j++;
	}
	cout<<vect.size()<<"\n";
	rep(i,vect.size()){
		cout<<vect[i].ft<<" "<<vect[i].sc<<"\n";
		}
	}
    return 0;
}
