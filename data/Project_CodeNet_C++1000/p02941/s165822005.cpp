#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 200005;
int n, a[MX], b[MX], c[MX], pr, nx;
long long cnt;
stack<int> st;
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", a+i);
	rep(i,n){
		scanf("%d", b+i);
		pr = i ? i-1 : n-1;
		nx = i != n-1 ? i+1 : 0;
		c[pr] += b[i];
		c[nx] += b[i];
		b[i] -= a[i];
	}
	rep(i,n) if(b[i] >= c[i]) st.push(i);
	while(!st.empty()){
		int t = st.top(); st.pop();
		int d = b[t] / c[t] * c[t];
		cnt += b[t] / c[t];
		pr = t ? t-1 : n-1;
		nx = t != n-1 ? t+1 : 0;
		c[pr] -= d; if(b[pr] >= c[pr]) st.push(pr);
		c[nx] -= d; if(b[nx] >= c[nx]) st.push(nx);
		b[t] -= d;
	}
	rep(i,n) if(b[i]) return 0*puts("-1");
	printf("%lld\n", cnt);
}