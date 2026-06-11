#define _USE_MATH_DEFINES
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<utility>
#include<map>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef vector<vector<int>> MX;

const ll MOD=1e9+7;
const int INF = 100000000;
vector<P> R;

int main()
{
	int N;
	cin>>N;
	int t=0;
	for(int i=0;i<N;i++)
	{
		int x,l;
		cin>>x>>l;
		t=min(t,x-l-1);
		R.push_back(make_pair(x+l,x-l));
	}
	sort(R.begin(),R.end());
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(t<=R[i].second)
		{
			ans++;
			t=R[i].first;
		}
	}
	cout<<ans<<endl;
}

