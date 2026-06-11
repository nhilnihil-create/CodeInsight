#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cout<<"->"<<#x<<" : "<<x<<endl;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c)) 
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef unsigned long long llu;
const double PI = 2*acos(0.0);
#define int long long
signed main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	cout<<(n/k+(n%k))-(n/k)<<endl;	
	return 0;
}