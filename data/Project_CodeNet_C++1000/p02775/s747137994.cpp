#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
/* Data Structure */
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define debug cerr << "======= GOT_HERE ======\n"
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef set<int> si;
typedef set<long long> sll;

long long n,k;

string s;

bool flag = false;

void addOne(string& a, int idx)
{
	if(idx<0)
	{
		flag = true;
		return;
	}
	int carry = 1;
	for(int i=idx;i>=0;--i)
	{
		int now = a[i]-'0'+carry;
		if(now!=10)
		{
			a[i] = now+'0';
			carry = 0;
			break;
		}
		else
		{
			a[i] = '0';
			carry = 1;
		}
	}
	if(carry)
	{
		flag = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n = s.length();
	ll ans = 0;
	for(int i=n-1;i>=0;--i)
	{
		if(s[i]-'0'<=4){
			ans+=s[i]-'0';
		}
		else if(s[i]-'0'>=6){ 
			ans+=10-(s[i]-'0');
			addOne(s,i-1);
		}
		else
		{
			if(i==0) ans+=5;
			else if(s[i-1]-'0'<5) ans+=5;
			else
			{
				ans+=5;
				addOne(s,i-1);
			}
		}
	}
	if(flag) ans++;
	cout << ans << endl;
	return 0;
}