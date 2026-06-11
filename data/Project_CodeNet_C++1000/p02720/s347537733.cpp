#include <cstdio>
#include <queue>
using namespace std;
int n;
bool flag=false;
void bfs(){
	queue<long long>q;
	for(int i=1;i<=9;++i){
		q.push(i);
	}
	while(!q.empty()){
		long long cur=q.front();
		q.pop();
		--n;
		if(n==0){
			printf("%lld\n",cur);
			return;
		}
		if(cur%10!=0)q.push(cur*10+cur%10-1);
		q.push(cur*10+cur%10);
		if(cur%10!=9)q.push(cur*10+cur%10+1);
	}
}
int main(){
	scanf("%d",&n);
	bfs();
	return 0;
}