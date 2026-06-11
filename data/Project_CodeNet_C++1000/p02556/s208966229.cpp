#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const int INF=0x3f3f3f3f;
const int N=1e6+7;
const int mod=1e9+7;
int maxn,minn;
int T,n,m,q;
int x[N];
int y[N];
int a[N],b[N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		scanf("%d%d", x + i, y + i);
		a[i] = x[i] + y[i];
		b[i] = x[i] - y[i];
	} 
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	cout <<	max(a[n] - a[1], b[n] - b[1]) << endl;
	


	return 0;
}

