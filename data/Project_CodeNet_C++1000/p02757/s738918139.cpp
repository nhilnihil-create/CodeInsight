#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int MAXN=2e5+50;
const int inf=0x3f3f3f3f;
const int M=5000*4;
char ch[MAXN];
int cnt[MAXN];
int main()
{
	int n,p;
	cin>>n>>p;
	cin>>(ch+1);
	ll ans=0;
	if(p==2||p==5){
		for(int i=1;i<=n;i++){
			if((ch[i]-'0')%p==0)ans+=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	int t=1,x=0;
	cnt[0]=1;
	for(int i=n;i>=1;i--){
		x=(x+(ch[i]-'0')*t)%p;
		
		ans+=cnt[x];
		cnt[x]++;

		t=t*10%p;
	}
	cout<<ans<<endl;
    return 0;
}
/*

*/

