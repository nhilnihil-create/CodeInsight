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
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef pair<int,int> P;

const int MOD=1000000007;
int main()
{
	LL a,b,c;
	cin>>a>>b>>c;
	if(c-a-b>=0 && (c-a-b)*(c-a-b)>4*a*b)cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
		
}