#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
#define X first
#define Y second
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
const int maxn=5e5+10;
const ll Inf=1e10;

ll ans;
ll n,k;
set<int>st;

//正向遍历一遍选择最小需要工作的天数，逆向遍历求解最大工作的天数，这样两者之间的交集就一定是需要工作的天数

int main(){

	int n,k,c;
	cin>>n>>k>>c;
	int res1[maxn],res2[maxn];
	string a;
	cin>>a;
	int pos=0;
	for(int i=0;i<n&&pos<k;i++){
		if(a[i]=='o'){
			res1[pos++]=i;
			i+=c;
		}
	}
	pos=k-1;
	for(int i=n-1;i>=0&&pos>=0;i--){
		if(a[i]=='o'){
			res2[pos--]=i;
			i-=c;
		}
	}
	for(int i=0;i<k;i++){
		if(res1[i]==res2[i]){
			cout<<res1[i]+1<<endl;
		}
	}
	return 0;
}