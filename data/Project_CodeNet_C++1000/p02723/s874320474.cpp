#include<bits/stdc++.h>
using namespace std;
#define very_slow       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define inf             1e18
#define MAX             1e9
#define MIN            -1e9
#define no_of_test(x)        int x; cin>>x; while(x--)
//Actual Code Is At The Top
const int mod = 1e9 + 7;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int binary_exponentation(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
int32_t main()
{   
	very_slow
//	no_of_test(x)
	{  
       string s;
       cin>>s;
       if(s[2]==s[3]&&s[4]==s[5])
       {
           cout<<"Yes"<<'\n';
       }
       else
       {
           cout<<"No"<<'\n';
       }
       
	}
	return 0;
}