#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,a[300000];
pii q[300000];
set<pii> S;
int main(){
	scanf("%d",&n);
	for (int i=0;i<1<<n;i++){
		scanf("%d",&a[i]);
		S.insert(pii(a[i],i));
    }
	set<pii>::iterator it;
	it=--S.end();
	q[1]=*it; S.erase(it);
	for (int i=1;i<=n;i++){
		int sz=1<<(i-1);
		sort(q+1,q+sz+1);
		reverse(q+1,q+sz+1);
		for (int j=1;j<=sz;j++){
			it=S.lower_bound(pii(q[j].fi,-1));
			if (it==S.begin())
				return puts("No"),0;
			q[j+sz]=*(--it);
			S.erase(it);
		}
	}
	puts("Yes");
}