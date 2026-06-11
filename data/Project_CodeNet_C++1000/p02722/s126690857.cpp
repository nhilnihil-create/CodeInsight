#include <iostream>
#include <map>
using namespace std;
long long n;
map <long long,long long> mp;
inline long long f(long long x)
{
	if(mp[x]) return 0;
	mp[x]=1;
	if(x==1) return 0;
	long long t=n;
	while(t%x==0) t/=x;
	return t%x==1; 
}
int main(int argc, char** argv) {
	cin >> n;
	long long ans=0;
	for(long long i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans+=f(i);
			if(i*i!=n) ans+=f(n/i); 
		}
	}
	for(long long i=1;i*i<=n-1;i++)
	{
		if((n-1)%i==0)
		{
			ans+=f(i);
			if(i*i!=n) ans+=f((n-1)/i);
		}
	}
	cout << ans;
	return 0;
}