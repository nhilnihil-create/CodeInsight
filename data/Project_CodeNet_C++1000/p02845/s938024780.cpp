#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

int ans=1;
int n,m;
int a[111111];
int cntcol[3];
signed main(){
	
	cin>>n;

	rep(i,n)cin>>a[i];
	if(a[0]!=0)ans=0;
	rep(i,n){
		if(i==0){
			ans*=3;
			cntcol[0]++;
		}
		else{
			int cnt=0;
			rep(j,3){
				if(cntcol[j]==a[i])cnt++;
			}
			rep(j,3){
				if(cntcol[j]==a[i]){
					cntcol[j]++;
					break;
				}
			}
			ans*=cnt;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
}
