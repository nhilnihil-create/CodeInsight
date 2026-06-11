#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll k;
int a[200005];
vector<int> vec;
bool used[200005];

int main(void){
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	vec.push_back(0);
	used[0]=true;
	int cur=a[0];
	while(!used[cur]){
		vec.push_back(cur);
		used[cur]=true;
		cur=a[cur];
	}
	int po=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i]==cur){
			po=i;
			break;
		}
	}
	if(k<po){
		printf("%d\n",vec[k]+1);
	}else{
		k-=po;
		int len=vec.size()-po;
		printf("%d\n",vec[(ll)k%(ll)len+po]+1);
	}
	return 0;
}
