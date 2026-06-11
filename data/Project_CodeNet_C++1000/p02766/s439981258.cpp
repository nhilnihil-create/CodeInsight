#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	ll n,k;
	cin>>n>>k;
	ll num = k;
	int ans = 1;
	while( num <= n){
		num = num * k; 
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

