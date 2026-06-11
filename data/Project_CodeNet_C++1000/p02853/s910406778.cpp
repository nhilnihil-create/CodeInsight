#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
int main()
{
	int x,y;cin>>x>>y;
	int sum = 0;
	sum += max(4-x,0);
	sum += max(4-y,0);
	if(sum==6)sum += 4;
	if(sum==0)cout<<0<<endl;
	else cout << sum << "00000" << endl;
}
