#include<bits/stdc++.h>
using namespace std;
struct qwq{
	int id;
	int have;
}a[100005];
	int n;
	inline bool cmp(qwq x,qwq y){
	return x.have<y.have;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d",&a[i].have);
	}
	stable_sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i].id);
	}
	return 0;
}