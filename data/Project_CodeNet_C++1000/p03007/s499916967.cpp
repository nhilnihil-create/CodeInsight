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
#define INF 2000001145
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
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

int ans=0;
int k,n;
int a[111111],b[111111];
signed main(){
	
	cin>>n;
	rep(i,n)cin>>a[i];
	sort(a,a+n);
	int l=a[0],r=a[n-1];
	for(int i=1;i<n-1;i++){
		if(a[i]<0){
			r-=a[i];
		}
		else{
			l-=a[i];
		}
	}
	cout<<abs(r-l)<<endl;
	l=a[0],r=a[n-1];
	for(int i=1;i<n-1;i++){
		if(a[i]<0){
			cout<<r<<" "<<a[i]<<endl;
			r-=a[i];
		}
		else{
			cout<<l<<" "<<a[i]<<endl;
			l-=a[i];
		}
	}
	cout<<r<<" "<<l<<endl;
}
