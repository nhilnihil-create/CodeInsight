#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
	string s;cin>>s;
	int n=s.length();
	int ans=n;
	int i=0;
	while(i<=n-2)
	{
		if(s[i]==s[i+1])
		{
			ans--;
			i+=3;
		}
		else i++;
	}
	cout<<ans<<"\n";
	return 0;
}