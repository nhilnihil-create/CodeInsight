#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n,k; cin >> n >> k;
	if(k>(n-1)*(n-2)/2){
		cout << -1<< endl;
		return 0;
	}
	vvi to(n);
	rep2(i,1,n) to[0].push_back(i);
	int m = n-1;
	int cnt = (n-1)*(n-2)/2-k;
	bool exitFlag=false;
	for(int u=1; u<n; u++){
		for(int v=u+1; v<n; v++){
			if(cnt==0){
				exitFlag=true;
				break;
			}			
			to[u].push_back(v);
			m++; cnt--;			
		}
		if(exitFlag)break;
	}
	cout << m << endl;
	rep(u,n)for(auto v:to[u]) cout << u+1 << " " << v+1 << endl;

}


