#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repa(i,a,n) for(int i=a;i<=n;i++)
#define repb(i,a,n) for(int i=a;i>=n;i--)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef long long ll;


void solve()
{
	int d,t,s;
	cin>>d>>t>>s;
	if(s*t>=d)
	{
		cout<<"Yes"<<endl;
	}else
	{
		cout<<"No"<<endl;
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t=1;
	//cin>>t;
    for(int i=0;i<t;i++)
    {
		//cout<<"Case #"<<i+1<<":"<<endl;
		solve();
	}
    return 0;
}
