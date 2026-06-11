#include<bits/stdc++.h>
#define fs first
#define se second
#define pb push_back
#define cppio ios::sync_with_stdio(false);cin.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;

const int maxn=2e3+5;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;

VI edge[maxn];

ll num[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		num[i]=1;
	}
	for(int i=3;i<=n;i++){
		for(int j=3;j<=n-i;j++){
			num[i+j]=(num[i+j]+num[i])%mod;
		}
	}
	printf("%lld",num[n]);
	return 0;
}
