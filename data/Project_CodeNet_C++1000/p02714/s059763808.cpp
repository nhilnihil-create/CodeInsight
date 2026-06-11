#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j,k
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl

int main()
{
	int64 nn, rr = 0, gg = 0, bb = 0, ans, kk;
	string ss;
	cin >> nn >> ss;
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(ss[ii] == 'R')
		{
			rr++;
		}
		else if(ss[ii] == 'G')
		{
			gg++;
		}
		else
		{
			bb++;
		}
	}
	ans = rr * gg * bb;
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = ii + 1;jj < nn;jj++)
		{
			kk = 2 * jj - ii;
			if(kk >= nn)
			{
				break;
			}
			if(ss[ii] != ss[jj] && ss[jj] != ss[kk] && ss[kk] != ss[ii])
			{
				ans--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}