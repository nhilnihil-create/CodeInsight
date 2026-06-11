#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
string s;
int m;
set<string> ans;
int main()
{
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		cin >> s;
		ans.clear();
		for(int j=1;j<s.size();j++)
		{
			string l,r,revl,revr;
			l=s.substr(0,j);
			r=s.substr(j);
			revl = l;
			revr = r;
			reverse(revl.begin(),revl.end());
			reverse(revr.begin(),revr.end());
			ans.insert(l+r);
			ans.insert(l+revr);
			ans.insert(r+revl);
			ans.insert(revl+revr);
			ans.insert(r+l);
			ans.insert(revr+l);
			ans.insert(revl+r);
			ans.insert(revr+revl);
		}
		printf("%d\n",(int)ans.size());
	}
	return 0;
}