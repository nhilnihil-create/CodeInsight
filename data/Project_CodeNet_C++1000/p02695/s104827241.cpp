#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

int N,M,Q;
struct node
{
	int a,b,c,d;
}qq[maxn];
int A[maxn];
int res = 0;
void dfs(int id,int last = 1){
	if(id > N){
		int sum = 0;
		for(int i = 1;i<=Q;i++){
			if(A[qq[i].b] - A[qq[i].a] == qq[i].c)
				sum += qq[i].d;
		}
		res = max(res,sum);
	}else{
		for(int i = last;i<=M;i++){
			A[id] = i;
			dfs(id+1,i);
		}
	}
}
int main(){
	// debug;
	ios;

	cin>>N>>M>>Q;
	for(int i = 1;i<=Q;i++){
		cin>>qq[i].a >> qq[i].b >> qq[i].c>>qq[i].d;
	}
	dfs(1);
	cout<<res<<'\n';

	return 0;
}
