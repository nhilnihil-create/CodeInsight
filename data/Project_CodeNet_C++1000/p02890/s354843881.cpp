#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+7;
int a[maxn];
vector<int> ans;vector<int> vec;vector<int> rem;
long double f(int u,int k)
{
	long double right=(long double)rem[u-1]/(long double)(k-u);
	return right;
}
int SanFen(int l,int r,int k) //找凸点  
{  
    while(l < r-1)  
    {  
        int mid  = (l+r)/2;  
        int mmid = (mid+r)/2;  
        if( f(mid,k) > f(mmid,k) )  
            l = mid;  
        else  
            r = mmid;  
    }  
    return f(l,k) > f(r,k) ? l : r;  
}  

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<maxn;i++)if(a[i]) vec.push_back(a[i]);
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=vec.size();i<=n;i++) vec.push_back(0);
	rem.push_back(n-vec[0]);
	for(int i=1;i<n;i++)rem.push_back(rem[i-1]-vec[i]);
	ans.push_back(n);
	for(int kpl=2;kpl<=n;kpl++)
	{
		int k=kpl;
		int l=SanFen(1,k,k);
		if(l>=k) l=k-1;
		if(l<=0) l=1;
		int cnt=rem[l-1]/(k-l);
		if(l>=0&&k!=l+1)
		cnt=min(cnt,rem[l]/(k-l-1));
		if(l+1<k-1)
		cnt=min(cnt,rem[l+1]/(k-l-2));
		cnt=min(cnt,n/k);
		ans.push_back(cnt);
	}
	for(auto u:ans) cout<<u<<endl;
 } 