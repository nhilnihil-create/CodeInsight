#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define int long long
#define all(arr) arr.begin(),arr.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vstr vector<string>
#define vbool vector<bool>
#define vvi vector<vector<int> >
#define mii map<int,int>
#define pb push_back
#define pii pair<int,int>
#define vpair vector<pii > 
#define mkp make_pair
#define scan(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) {cout<<a[i]<<' ';}cout<<'\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loope(i,a,b) for (int i = a; i <= b; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout.unsetf ( std::ios::fixed );std::cout.precision(9)
#define PI 3.14159265
#define S second
#define F first
#define CHECK cout<<"CHEDEDWB"<<endl
#define br '\n'
/*int mod = 1e9+7;
int inf = 1e18;
int m_inf = INT_MIN;
int MOD = 100001;*/

void solve()
{
	string s,t;
	cin>>s>>t;
	int ans = 0;
	loop(i,0,3)
	{
		if(s[i]==t[i])
			ans++;
	}
	cout<<ans<<endl;
}

int32_t main()
{
	FastIO; PRECISION;
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}