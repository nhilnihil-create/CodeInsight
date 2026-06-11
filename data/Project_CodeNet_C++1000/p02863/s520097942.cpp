#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

ll dp[3010][3010];

int main(void){
	int n,t;
	cin>>n>>t;
	vector<P>p(n);
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		p[i]=make_pair(a,b);
	}
	sort(p.begin(),p.end());
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<t;j++){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			int nj = j+p[i].first;
			if(nj<t)dp[i+1][j+p[i].first]=max(dp[i+1][j+p[i].first],dp[i][j]+p[i].second);
		}
		int now = dp[i][t-1]+p[i].second;
		ans = max(ans,now);
	}
	cout<<ans<<endl;
    return 0;
}