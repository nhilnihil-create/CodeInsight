#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define inf 1000000005
#define MOD 1000000007 
#define N 300005
#define M 1000000
#define LOG 17
#define KOK 300
#define EPS 0.0000001
using namespace std;

int sz;
int pre[N],a[N];
int n;

void s0(int ad) {

	for(int i=1;i<ad;i++) {

		printf("%d %d\n",i,i+1);
		printf("%d %d\n",n+i,n+i+1);

	}

	printf("%d %d\n",ad,n+1);

}

void no() {printf("No");exit(0);}

void solve() {

	if(n%4==0) {

		int f=n;

		while(f%2==0) f/=2;

		if(f==1) no();

		for(int i=1;i<n;i++) a[++sz]=i;
		for(int i=1;i<n;i++) a[++sz]=i;		

		for(int i=1;i<=sz;i++) pre[i]=pre[i-1]^a[i];

		map<int,int> ok;

		ok[pre[0]]=0;

		for(int i=1;i<=sz;i++) {

			if(ok.find(pre[i]^n)!=ok.end()) {

				printf("Yes\n");

				s0(n-1);

				printf("%d %d\n",n,ok[pre[i]^n]+1);
				printf("%d %d\n",n+n,i);

				exit(0);

			}

			ok[pre[i]]=i;

		}

		no();

	}
	else if(n%4==1) {

		printf("Yes\n");

		s0(n-2);

		printf("%d %d\n",n,n-1);
		printf("%d %d\n",n-1,1);
		printf("%d %d\n",1,n+n);
		printf("%d %d\n",n+n,n+n-1);

	}
	else {

		printf("Yes\n");

		s0(n-3);

		printf("%d %d\n",n-1,n-2);
		printf("%d %d\n",n-2,1);
		printf("%d %d\n",1,n+n-1);
		printf("%d %d\n",n+n-1,n+n-2);
		printf("%d %d\n",n+n-1,n);
		printf("%d %d\n",n+n,2);

	}

}

int main() {

	scanf("%d",&n);

	if(n<3) {printf("No");exit(0);}

	int xx=0;

	for(int i=1;i<=n;i++) xx^=i;

	if(xx) {

		solve();

		return 0;

	}

	printf("Yes\n");

	s0(n);

}	