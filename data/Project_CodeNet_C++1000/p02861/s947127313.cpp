#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul  unsigned long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod
//ll divide(ll a, ll b)  //euler's theorem(a/b)%mod
//{
//   return a*power(b,mod-2)%mod;  //only when mod is prime
//}

ll power(ll x, ll y)
{
    ll res = 1;
   while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int main()
{
    speed;
    int n;
    cin>>n;
    vector<int>v(n);
	vector<pair<int,int>> point(n+1);
    for(int i=1;i<=n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	point[i]={x,y};
    	v[i-1]=i;
    }
	long double sum=0;
		for(int i=0;i<n-1;i++)
		{
			long double x1=point[v[i]].first,y1=point[v[i]].second,x2=point[v[i+1]].first,y2=point[v[i+1]].second;
			x1=x1-x2;
			y1=y1-y2;
			sum+=sqrt(x1*x1+y1*y1);

		}
	while(next_permutation(v.begin(), v.end()))
	{
		for(int i=0;i<n-1;i++)
		{
			long double x1=point[v[i]].first,y1=point[v[i]].second,x2=point[v[i+1]].first,y2=point[v[i+1]].second;
//			cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
//            cout<<v[i]<<" "<<v[i+1]<<' ';
			long double t1=x1-x2 , t2=y1-y2;
//			cout<<sqrt(t1*t1+t2*t2)<<"sff "<<'\n';
			sum+=sqrt(t1*t1+t2*t2);
		}
	}
	int t=1;
	for(int i=1;i<=n;i++)
	t=t*i;
	
	cout<<setprecision(11)<<sum/t<<'\n';


	return 0;
}
