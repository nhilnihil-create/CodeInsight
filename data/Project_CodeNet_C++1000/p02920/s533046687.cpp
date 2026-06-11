#include<cstdio>
#include<queue>
#include<algorithm>
const int N = (1<<19)+5;
int a[N];
int cnt[N];
std::priority_queue<int>Q;

int main(){
	int n;
	scanf("%d",&n);
	int m = 1<<n;
	for(int i = 1; i <= m; i++) scanf("%d",&a[i]);
	std::sort(a+1,a+1+m);
	int p = m; Q.push(n);
	int ok = 1;
	while(p>=1){
		int next = p;
		while(next>=1 && a[next]==a[p]) next--;
		if(p-next>Q.size()){
			ok = 0;
			break;
		}
		else{
			for(int i = p; i > next; i--){
				cnt[i] = Q.top();
				Q.pop();
			}
			for(int i = p; i > next; i--){
				for(int j = cnt[i]-1; j >= 0; j--) Q.push(j);
			}
			p = next;
		}
	}
	//printf("%d\n",Q.size());
	if(ok) printf("Yes\n");
	else printf("No\n"); 
	return 0;
}