#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define debug(n) cout<<"# "<<#n<<": "<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(c,i) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main()
{
	vi a;
	for(int n;cin>>n;)
		a.push_back(n);
	
	vi hist(101);
	rep(i,a.size())
		hist[a[i]]++;
	
	int mode_count=*max_element(allof(hist));
	rep(i,hist.size())
		if(hist[i]==mode_count)
			cout<<i<<endl;
	
	return 0;
}