#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ll long long
#define INF INT_MAX
#define mod 1000000007
#define chutiyaap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll t = pw(a, b / 2);
    if (b % 2 == 0) return (t * t)%mod;
    else return ((t * t)%mod * a)%mod;
}
int main()
{
	int n;cin>>n;
	int a[n];for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
    int count=0;
    int i=0;
    int j=i+1;
    while(i<n-2)
    {
        int k=j+1;
        while(k<n&&a[k]<a[i]+a[j])k++;
        count += k-j-1;
        j++;
        if(j>=n)
        {
            i++;
            j = i+1;
        }
    }
    cout<<count;
}
