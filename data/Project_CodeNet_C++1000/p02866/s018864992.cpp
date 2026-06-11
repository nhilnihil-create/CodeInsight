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

int ans=1;
int k,n;
int a[111111];
int cnt[111111];

long long mod_pow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
	cin>>n;
	int lim=0;
	rep(i,n){
		cin>>a[i];
		cnt[a[i]]++;
		lim=max(a[i],lim);
	}
	if(lim==0 && cnt[0]!=1)ans=0;
	if(cnt[0]>1 || a[0]!=0)ans=0;
	for(int i=1;i<=lim;i++){
		if(cnt[i]==0 || cnt[0]==0)ans=0;
		ans*=mod_pow(cnt[i-1],cnt[i],998244353);
		ans%=998244353;
	}
	cout<<ans<<endl;
}
