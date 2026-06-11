

  /********************************************************
  **░██████╗██╗░░░░░░█████╗░██╗░░░██╗██╗░█████╗░░██████╗░**
  **██╔════╝██║░░░░░██╔══██╗██║░░░██║██║██╔══██╗██╔════╝░**
  **╚█████╗░██║░░░░░███████║╚██╗░██╔╝██║██║░░╚═╝██║░░██╗░**
  **░╚═══██╗██║░░░░░██╔══██║░╚████╔╝░██║██║░░██╗██║░░╚██╗**
  **██████╔╝███████╗██║░░██║░░╚██╔╝░░██║╚█████╔╝╚██████╔╝**
  **╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░░╚═════╝░**
  *********************************************************/

#include <bits/stdc++.h>
using namespace std;


#define ll                          long long
#define ld                          long double

#define forn(i,n)                   for(int i=0;i<n;++i)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend();
#define isSubstring(s1,s2)          s1.find(s2) != std::string::npos
	
#define pb                          push_back
#define pf                          push_front
#define mp                          make_pair
#define fr                          first
#define sc                          second

#define vpi                         <vector<pair<int,int>>
#define vi                          vector<int>
#define sz(a)                       (int)a.size()

#define   endl                       "\n"
#define     nl                       cout<<"\n";
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define MN                           INT_MIN
#define MX                           INT_MAX

bool isPrime(ll n){if(n<2)return false;for(ll x = 2;x*x <=n;x++){if(n%x == 0)return false;}return true;}
bool isPerfectSquare(long double x){long double sr=sqrt(x);return((sr-floor(sr))==0);}
int gcd(int a, int b){if(a==0)return b;if(b==0) return a;if(a==b)return a;if(a>b)return gcd(a-b,b);return gcd(a,b-a);}
int lcm(int a, int b){return(a*b)/gcd(a, b);}  


int32_t main()
{
	int n;
	cin >> n;
	int a[n+1];
	bool one = false;
	for(int i = 1 ;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]== 1)one = true;
	}
	if(!one){
		cout << -1<<endl;
		return 0;
	}
	int need = 1;
	int k = 0;
	for(int i=  1;i<= n;i++)
	{
		if(a[i] != need)
		{
			k++;
		}else{
			need++;
		}
	}
	cout << k << endl;
}