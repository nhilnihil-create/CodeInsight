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
int gcd(int a, int b) {
    if(b > a) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}
vector<int> enum_div(int n)//nの約数を列挙
{
	vector<int> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    int G = gcd(A, B);
    vector<int> v = enum_div(G);
    sort(v.begin(), v.end());
    set<int> st;
    for(auto &e: v) st.insert(e);
    int ans = 0;
    for(auto &e: v) {
        if(st.find(e) != st.end()) {
            //cerr << e << endl;
            ans++;
            auto itr = st.begin();
            if(e == 1) continue;
            while(itr != st.end()) {
                int num = *itr;
                if(num % e == 0) {
                    itr = st.erase(itr);
                } else {
                    itr++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
