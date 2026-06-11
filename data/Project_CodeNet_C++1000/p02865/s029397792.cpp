#define debug_switch
#ifdef debug_switch
#define debug if(1) puts("debug");
#define dout if(1) cout
#else
#define debug if(0) puts("debug");
#define dout if(0) cout
#endif
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-7;
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<((n+1)/2 - 1)<<endl;
	return 0;
}




