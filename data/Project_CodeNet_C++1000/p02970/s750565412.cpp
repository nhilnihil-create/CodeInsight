#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<map> 
#include<list>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#define ll long long
#define memset(a,n) memset(a,n,sizeof(a))
#define mp make_pair 
#define pb push_back
using namespace std;
const int maxn = 1e6 + 100;

int main()
{
	int n,k;cin >> n >> k;
	int ans = n / (2 * k + 1);
	if(n % (2 * k + 1) != 0) ans++;
	cout << ans << endl;
}
