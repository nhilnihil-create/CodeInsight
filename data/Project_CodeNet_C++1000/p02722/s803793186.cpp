#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
set<int> enum_div(int n)//nの約数を列挙
{
	set<int> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.insert(i);
			if(i*i!=n)
			{
				ret.insert(n/i);
			}
		}
	}
	return ret;
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    set<int> st = enum_div(N - 1);
    set<int> st2 = enum_div(N);
    for(auto& e: st2) st.insert(e);
    st.erase(1);
    st.insert(2);
    st.insert(N);
    int ans = 0;
    for(auto e: st) {
        int num = N;
        while(num % e == 0) num /= e;
        if(num % e == 1) ans++;
    } 
    cout << ans << endl;



    return 0;
}
