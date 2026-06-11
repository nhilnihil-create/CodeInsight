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
//typedef long long int LL;
typedef pair<int,int> P;

const int MOD=1000000007;
int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main()
{
	int k;
	cin>>k;k--;
	cout<<a[k]<<"\n";	
}