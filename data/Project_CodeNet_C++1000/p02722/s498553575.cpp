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
#define INF 2000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;

int n,k,ans;
int x,y;
signed main(){
	cin>>n;
	for(int i=1;i*i<=n-1;i++){
		if((n-1)%i==0){
			if(i*i!=n-1)ans+=2;
			else ans++;
		}
	}
	ans--;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int n2=n;
			while(n2%i==0){
				n2/=i;
			}
			if(n2%i==1)ans++;
		}
	}
	ans++;
	cout<<ans<<endl;
}