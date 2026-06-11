#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200090;

int n,x[maxn],m,ans;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans=2e9+7,m=0;
	n = read();
	for(int i = 1;i <= n;i++) {
		x[i] = read();
		m=max(m,x[i]);
	}
	
	int t=0;
	for(int i = 1;i <= m ;i++) {
		for(int j = 1 ; j <= n; j++){
			t+=(i-x[j])*(i-x[j]);
		}
		ans=min(ans,t);
		t = 0;
	}  
	printf("%d\n",ans);
	
	return 0;
}