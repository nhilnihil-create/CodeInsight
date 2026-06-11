#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
 
inline int read()
{
    int X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}
 
int s;
int dp[N];

int main() {
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	s=read();
	dp[0]=1;
	for(int i=1;i<=s;++i){
		for(int j=0;j<=i-3;++j){
			dp[i]+=dp[j];
			dp[i]%=mod;
		}
	}
	printf("%d\n",dp[s]);

    return 0;
}