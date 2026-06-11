#include"bits/stdc++.h"
using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

int32_t main()
{
	FastIO;
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(n) n/=k, ans++;
    cout<<ans;
	return 0;
}
