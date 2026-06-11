/*Lucky_Glass*/
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int totA;
vector< pair<int,int> > ans;

int main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	if(n<3) printf("No\n"),exit(0);
	for(int i=2;i<n;i+=2)
		ans.emplace_back(i,i+1),
		ans.emplace_back(i+n,i+1+n),
		ans.emplace_back(i,1),
		ans.emplace_back(i+1+n,1);
	ans.emplace_back(3,n+1);
	if(n%2==0){
		int x=(n&-n);
		if(x==n) printf("No\n"),exit(0);
		ans.emplace_back(x+1+n,n);
		ans.emplace_back(n-x,n+n);
	}
	printf("Yes\n");
	for(auto it : ans)
		printf("%d %d\n",it.first,it.second);
	return 0;
}