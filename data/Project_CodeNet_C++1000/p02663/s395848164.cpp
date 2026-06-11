//Never stop chasing!-MdSourav.
#include <bits/stdc++.h>

#define yes            cout<<"YES"<<endl
#define no             cout<<"NO"<<endl
#define sz(x)          x.size()
#define ll                    long long int
#define ls             long int
#define start          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test           int t;cin>>t;while(t--)
#define f(i, a, n)     for(int i=a; i<n;i++)
#define gcd(a,b)7           __gcd(a,b)
#define lcd(a,b)       (a*b)/gcd(a,b)
#define pb             push_back
#define mp(x,y)        make_pair(x,y)
#define rsrt(v)        sort(v.begin(),v.end(),greater<int>())
#define srt(v)         sort(v.begin(),v.end())
#define basrt(a,n)     sort(a,a+n,greater<int>())
#define asrt(a,n)      sort(a,a+n)
#define fact(n)        ll x=1;for(ll i=1;i<=n;i++){x=(x*i);}
#define F              first
#define S              second
#define deb(x)         cout << #x << ": " << x << endl;
#define enter(v,n)     for(ll i=0;i<n;i++){ll x;cin>>x;v.pb(x);}
#define INF 	       1000000007
#define unique(v)      v.erase(unique(v.begin(),v.end()),v.end())
using namespace std;

double pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664 ;
typedef vector<ll> vll ;
typedef vector<int> vii ;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v) os << " " << x;
        return os << '}';
}

void solve()
{

        int a,b,a1,b1,c;
        cin>>a>>b>>a1>>b1>>c;
        int x=0,x1,x3=0;
        if(b>b1)
		{
			x3=b-b1;
		}
		else
		{
			x=b1-b;
		}
		x1=a1-a;
		int ans=x1*60;
		ans=ans+x-x3;
		ans=ans-c;
		cout << ans << endl;


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    ll test_case=1;
    //cin>>test_case ;
    while(test_case--)
	{
		 solve();
	}

	return 0;
}