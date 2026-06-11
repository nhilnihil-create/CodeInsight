#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[505],k,q[505],m[505]; 
V<int> t;
bool check(int p){
	FOR(i,1,n)m[i]=a[i]%p;
	sort(m+1,m+n+1); 
	for(int i=n;i>=1;i--)q[i]=q[i+1]+p-m[i];
	int sum=0;
	FOR(i,0,n){
		sum+=m[i];
		if(sum==q[i+1])break;
	}
	return (sum<=k);
} 
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>k;
	int sum=0,st;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	st=sqrt(sum);
	FOR(i,1,st){
		if(sum%i==0){
			t.PB(i);
			if(i*i!=sum)t.PB(sum/i);
		}
	}
	sort(ALL(t),greater<int>());
	for(int i=0;i<t.size();i++){
		if(check(t[i])){
			cout<<t[i];break;
		}
	}
	RE 0;
}


