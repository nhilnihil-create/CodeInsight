                                                                   //author rhythmicankur
                                                                  //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define int     long long
#define ll      int
#define ld 		long double
#define pb 		push_back
#define eb 		emplace_back
#define mk 		make_pair
#define vi 		vector<int>
#define pii 		pair<int,int>
#define pip             pair<int,pii>
#define vpi 		vector<pii>
#define sbcount(x) __builtin_popcountll(x)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define trav(a, x)      for(auto& a : x)
#define all(x)          x.begin(), x.end()
#define fill(a,val)	memset(a,val,sizeof(a))
#define 	PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 	998244353
#define M2 	1000000007
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); } 
#define test4(x,y,z,a) 		    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"  |  "<<#a<<": "<<a<<endl;
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl(){cout<<"Control"<<endl;}
int make_num(string p){stringstream geek(p); int x = 0; geek >> x;return x;}
string make_str(int x){ostringstream str1; str1 << x; string geek = str1.str(); return geek;}

signed main()
{	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin.exceptions(cin.failbit);
	int k,x;
    cin>>k>>x;
    if(k*500>=x)
    cout<<"Yes";
    else
    {
        cout<<"No";
    }
    

return 0;
}