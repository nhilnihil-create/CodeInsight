#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
#define mod 1000000007
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
vector<ll> vec;
vector<ll> arr;
bool ans[200005];
int main()
{
	ios;
	memset(ans,false,sizeof(ans));
	ll n,k,c,i,prev,f,len,l,d;
	char ch;
	cin>>n>>k>>c;
	arr.push_back(-c-1);
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='o')
			vec.push_back(i);
	}
	prev=-c-1;f=0;
	for(i=0;i<vec.size();i++)
	{
		if(f==k)
			break;
		if(vec[i]-prev>c)
		{
			//cout<<vec[i]<<endl;
			arr.push_back(vec[i]);
			prev=vec[i];
			f++;
		}
	}
	len=vec.size();
	d=len-1;prev=n+c+1;
	l=arr.size();
	for(i=l-1;i>=1;i--)
	{
		while(d>=0&&vec[d]>arr[i]&&(prev-vec[d])<=c)
			d--;
		if(d>=0&&vec[d]!=arr[i])
			prev=vec[d];
		else
		{
			prev=arr[i];
			//cout<<arr[i]<<" "<<vec[d]<<endl;
			ans[arr[i]]=true;
		}
		//cout<<arr[i]<<" "<<vec[d]<<endl;
	}
	for(i=1;i<=n;i++)
	{
		if(ans[i])
			cout<<i<<endl;
	}
}
