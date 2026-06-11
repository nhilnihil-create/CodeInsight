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
//#define int long long
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

int n,k;
string s;
vector<P> ans;
signed main(){
	cin>>n>>k;
	rep(i,n-1){
		ans.push_back(P(1,i+2));
	}//この時点で(n-2+1)(n-2)/2=(n-1)(n-2)/2個
	int nowcnt=(n-1)*(n-2)/2;
	if(nowcnt==k){
		cout<<ans.size()<<endl;
		for(auto x:ans){
			cout<<x.first<<" "<<x.second<<endl;
		}
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans.push_back(P(i,j));
			nowcnt--;
			if(nowcnt==k){
				cout<<ans.size()<<endl;
				for(auto x:ans){
					cout<<x.first<<" "<<x.second<<endl;
				}
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	
}