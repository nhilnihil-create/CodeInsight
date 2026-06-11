#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
//#define for(i,a,b) for(int i=(a);i<=(b);i++)

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,x;
cin>>k>>x;
for(int i=(x-(k-1));i<=(x+k-1);i++)
{
    cout<<i<<" ";
}
}