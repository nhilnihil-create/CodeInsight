#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
// #include <cmath>
// #include <map>
// #include <set>
// #include <deque>
// #include <stack>
// #include <vector>
using namespace std;
#define debug freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define PI acos(-1)
typedef long long ll;
const int mod=1e9+7;

int main()
{
	//debug;
	ios;
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max(max(a*c,a*d),max(b*c,b*d));
}