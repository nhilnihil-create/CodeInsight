#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define mp make_pair
#define pb push_back
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define pi 3.14159265358979323846
#define reus ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	reus;

//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
    
    int n,i,c=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    	if(a[i]%2==0)
    	c++;
	}
	int k=0;
	for(i=0;i<n;i++)
	{
		if((a[i]%2==0)&&((a[i]%3==0)||a[i]%5==0))
		k++;
	}
	//cout<<c<<" "<<k<<endl;
    if(c==k)
    cout<<"APPROVED"<<endl;
    else
    cout<<"DENIED"<<endl;
	return 0;
}